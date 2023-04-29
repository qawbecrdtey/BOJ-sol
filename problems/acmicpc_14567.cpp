#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto v = new vector<int>[n + 1];
    auto d = new int[n + 1]();
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        d[y]++;
    }
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++) {
        if(!d[i]) q.emplace(i, 1);
    }
    auto res = new int[n + 1];
    while(!q.empty()) {
        auto [now, time] = q.front(); q.pop();
        res[now] = time;
        for(auto next : v[now]) {
            d[next]--;
            if(!d[next]) {
                q.emplace(next, time + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
}