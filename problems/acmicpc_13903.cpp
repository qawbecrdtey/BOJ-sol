#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new bool*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new bool[m];
        visited[i] = new bool[m]();
        for(int j = 0; j < m; j++) {
            int x; cin >> x; a[i][j] = (x != 0);
        }
    }
    int o; cin >> o;
    auto dir = new pair<int, int>[o];
    for(int i = 0; i < o; i++) {
        cin >> dir[i].first >> dir[i].second;
    }
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < m; i++) {
        if(a[0][i]) q.emplace(0, i, 0);
    }
    while(!q.empty()) {
        auto const [nowi, nowj, nowcnt] = q.front(); q.pop();
        if(visited[nowi][nowj]) continue;
        visited[nowi][nowj] = true;
        if(nowi == n - 1) {
            cout << nowcnt;
            return 0;
        }
        for(int i = 0; i < o; i++) {
            auto const [di, dj] = dir[i];
            if(nowi + di < 0 || nowj + dj < 0 || nowi + di >= n || nowj + dj >= m) continue;
            if(!a[nowi + di][nowj + dj] || visited[nowi + di][nowj + dj]) continue;
            q.emplace(nowi + di, nowj + dj, nowcnt + 1);
        }
    }
    cout << -1;
}
