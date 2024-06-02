#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
vector<int> compute_dist(int const r, int const c, bool const *const *const visited_template, pair<int, int> const car, vector<pair<int, int>> const &lots) {
    auto visited = new bool*[r];
    for(int i = 0; i < r; i++) {
        visited[i] = new bool[c];
        copy(visited_template[i], visited_template[i] + c, visited[i]);
    }

    vector<int> dist(lots.size(), -1);
    queue<tuple<int, int, int>> q;
    q.emplace(car.first, car.second, 0);
    while(!q.empty()) {
        auto const [nowx, nowy, nowdist] = q.front(); q.pop();
        if(visited[nowx][nowy]) continue;
        visited[nowx][nowy] = true;
        if(auto const it = lower_bound(lots.begin(), lots.end(), make_pair(nowx, nowy)); it != lots.end() && it->first == nowx && it->second == nowy) {
            dist[it - lots.begin()] = nowdist;
        }
        if(nowx && !visited[nowx - 1][nowy]) q.emplace(nowx - 1, nowy, nowdist + 1);
        if(nowy && !visited[nowx][nowy - 1]) q.emplace(nowx, nowy - 1, nowdist + 1);
        if(nowx < r - 1 && !visited[nowx + 1][nowy]) q.emplace(nowx + 1, nowy, nowdist + 1);
        if(nowy < c - 1 && !visited[nowx][nowy + 1]) q.emplace(nowx, nowy + 1, nowdist + 1);
    }

    for(int i = 0; i < r; i++) delete[] visited[i];
    delete[] visited;

    return dist;
}
class graph {
    struct vertex;
    struct edge {
        vertex *from;
        vertex *to;
        int capacity;
        edge *reverse;
        edge(vertex *from, vertex *to, int capacity) : from(from), to(to), capacity(capacity), reverse(nullptr) {}
        static pair<edge*, edge*> add_edge(vertex *from, vertex *to) {
            auto forward = new edge(from, to, 1);
            auto reverse = new edge(to, from, 0);
            forward->reverse = reverse;
            reverse->reverse = forward;
            return {forward, reverse};
        }
        void fill(int f) {
            capacity -= f;
            reverse->capacity += f;
        }
    };
    struct vertex {
        vector<edge*> edges;
        void add_edge(vertex *to) {
            auto [forward, reverse] = edge::add_edge(this, to);
            edges.push_back(forward);
            to->edges.push_back(reverse);
        }
    };

    int n;
    vertex *vertices;
public:
    graph(int n) : n(n), vertices(new vertex[n]) {}
    ~graph() {
        for(int i = 0; i < n; i++) {
            for(auto const e : vertices[i].edges) {
                delete[] e;
            }
        }
        delete[] vertices;
    }
    void add_edge(int from, int to) {
        vertices[from].add_edge(vertices + to);
    }
    int flow() {
        auto const prev = make_unique<edge*[]>(n);
        struct info { int now; edge *e; };
        queue<info> q;
        q.push({0, nullptr});
        while(!q.empty()) {
            auto [n, e] = q.front(); q.pop();
            if(n && prev[n]) continue;
            prev[n] = e;
            if(n == 1) {
                while(e) {
                    e->fill(1);
                    e = prev[e->from - vertices];
                }
                return 1;
            }
            for(auto const next_e : vertices[n].edges) {
                auto const next = static_cast<int>(next_e->to - vertices);
                if(!next || !next_e->capacity || prev[next]) continue;
                q.push(info{next, next_e});
            }
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int r, c; cin >> r >> c;
    auto a = new string[r];
    auto visited_template = new bool*[r];
    vector<pair<int, int>> cars, lots;
    for(int i = 0; i < r; i++) {
        visited_template[i] = new bool[c]();
        cin >> a[i];
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'C') cars.emplace_back(i, j);
            else if(a[i][j] == 'P') lots.emplace_back(i, j);
            else if(a[i][j] == 'X') visited_template[i][j] = true;
        }
    }
    delete[] a;
    if(lots.empty()) {
        cout << -!cars.empty();
        return 0;
    }
    if(cars.empty()) {
        cout << 0;
        return 0;
    }
    sort(lots.begin(), lots.end());
    vector<vector<int>> dists;
    int max_dist = 0;
    for(auto const &car : cars) {
        dists.push_back(compute_dist(r, c, visited_template, car, lots));
        auto const m = *max_element(dists.back().begin(), dists.back().end());
        if(m == -1) { cout << -1; return 0; }
        max_dist = max(max_dist, m);
    }

    int const cars_size = static_cast<int>(cars.size());
    int const lots_size = static_cast<int>(lots.size());
    
    int left = 0, right = max_dist + 1;
    while(left < right) {
        auto const m = (left + right) >> 1;
        graph f(cars_size + lots_size + 2);
        for(int i = 0; i < cars_size; i++) f.add_edge(0, i + 2);
        for(int i = 0; i < lots_size; i++) f.add_edge(i + cars_size + 2, 1);
        for(int i = 0; i < cars_size; i++) {
            for(int j = 0; j < lots_size; j++) {
                if(dists[i][j] != -1 && dists[i][j] <= m) {
                    f.add_edge(i + 2, j + cars_size + 2);
                }
            }
        }
        int F, cap = 0;
        while((F = f.flow())) cap += F;
        if(cap == cars_size) right = m;
        else left = m + 1;
    }
    if(right == max_dist + 1) cout << -1;
    else cout << right;
}
