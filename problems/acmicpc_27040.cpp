#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[m];
    for(int i = 0; i < m; i++) cin >> a[i];
    auto visited = new bool[n + 401 * 32]();
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == n) {
            cout << cnt;
            return 0;
        }
        for(int i = 0; i < m; i++) {
            if(now + a[i] < n + 401 * 32 && !visited[now + a[i]]) q.emplace(now + a[i], cnt + 1);
            if(now - a[i] >= 0 && !visited[now - a[i]]) q.emplace(now - a[i], cnt + 1);
        }
    } cout << 0;
}