#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool connected(vector<pair<int, int>> const *v, int const n, int const cost, int const start, int const end) {
    static auto const visited = new bool[n + 1];
    fill_n(visited, n + 1, false);
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        auto const now = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == end) return true;
        for(auto const [next, next_cost] : v[now]) {
            if(visited[next] || next_cost < cost) continue;
            q.push(next);
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto const v = new vector<pair<int, int>>[n + 1];
    int mx = 0;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
        mx = max(mx, c);
    }
    int s, e; cin >> s >> e;
    int l = 0, r = mx + 1, res = 0;
    while(l < r) {
        if(int const mid = (l + r) >> 1; !connected(v, n, mid, s, e)) r = mid;
        else res = mid, l = mid + 1;
    }
    cout << res;
}