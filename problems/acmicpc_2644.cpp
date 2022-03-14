#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, s, t, m; cin >> n >> s >> t >> m;
    auto v = new vector<int>[n + 1];
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<pair<int, int>> q;
    q.push({ s, 0 });
    auto visited = new bool[n + 1]();
    while(!q.empty()) {
        auto const [now, dist] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == t) {
            cout << dist;
            return 0;
        }
        for(auto next : v[now]) {
            if(!visited[next]) q.push({ next, dist + 1 });
        }
    }
    cout << -1;
}