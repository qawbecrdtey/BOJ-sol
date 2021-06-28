#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int min_path(vector<pair<int, int>> const *v, int n, int s, int e) {
    auto visited = make_unique<bool[]>(n + 1);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        auto const now = pq.top(); pq.pop();
        if(visited[now.second]) continue;
        visited[now.second] = true;
        if(now.second == e) return -now.first;
        for(auto const &next : v[now.second]) {
            if(!visited[next.second]) pq.push(make_pair(now.first + next.first, next.second));
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto v = new vector<pair<int, int>>[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(-c, b);
        v[b].emplace_back(-c, a);
    }
    int a, b;
    cin >> a >> b;
    int const sa = min_path(v, n, 1, a);
    int const sb = min_path(v, n, 1, b);
    int const ab = min_path(v, n, a, b);
    int const ae = min_path(v, n, a, n);
    int const be = min_path(v, n, b, n);
    int const x = sa + ab + be;
    int const y = sb + ab + ae;
    if(ab == -1 || sa == -1 || ae == -1) {
        cout << -1;
        goto END;
    }
    cout << (x > y ? y : x);
END:delete[] v;
}