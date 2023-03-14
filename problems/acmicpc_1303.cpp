#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new string[m];
    auto visited = new bool*[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        visited[i] = new bool[n]();
    }
    long long res[2]{};
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j]) continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            long long cnt{};
            while(!q.empty()) {
                auto const [nowx, nowy] = q.front(); q.pop();
                if(visited[nowx][nowy]) continue;
                visited[nowx][nowy] = true;
                cnt++;
                if(nowx && !visited[nowx - 1][nowy] && a[i][j] == a[nowx - 1][nowy]) q.emplace(nowx - 1, nowy);
                if(nowy && !visited[nowx][nowy - 1] && a[i][j] == a[nowx][nowy - 1]) q.emplace(nowx, nowy - 1);
                if(nowx < m - 1 && !visited[nowx + 1][nowy] && a[i][j] == a[nowx + 1][nowy]) q.emplace(nowx + 1, nowy);
                if(nowy < n - 1 && !visited[nowx][nowy + 1] && a[i][j] == a[nowx][nowy + 1]) q.emplace(nowx, nowy + 1);
            }
            res[a[i][j] != 'W'] += cnt * cnt;
        }
    }
    cout << res[0] << ' ' << res[1];
}