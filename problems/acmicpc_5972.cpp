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
    }
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    auto visited = new bool[n + 1]();
    while(!pq.empty()) {
        auto const [cost, now] = pq.top(); pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == n) {
            cout << -cost;
            return 0;
        }
        for(auto [next_cost, next] : v[now]) {
            if(visited[next]) continue;
            pq.emplace(cost + next_cost, next);
        }
    }
}
