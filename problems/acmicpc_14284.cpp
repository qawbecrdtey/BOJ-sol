#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto v = new vector<pair<int, int>>[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(-c, b);
        v[b].emplace_back(-c, a);
    } int s, t; cin >> s >> t;
    priority_queue<pair<int, int>> pq;
    auto visited = new bool[n + 1]();
    for(auto const [cost, now] : v[s]) pq.emplace(cost, now);
    while(!pq.empty()) {
        auto const [cost, now] = pq.top(); pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == t) {
            cout << -cost;
            return 0;
        }
        for(auto const [nextcost, next] : v[now]) {
            if(visited[next]) continue;
            pq.emplace(cost + nextcost, next);
        }
    } __builtin_unreachable();
}