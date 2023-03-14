#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        visited[i] = new bool[m]();
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int cnt{};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] || !a[i][j]) continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            cnt++;
            while(!q.empty()) {
                auto const [nowx, nowy] = q.front(); q.pop();
                if(visited[nowx][nowy]) continue;
                visited[nowx][nowy] = true;
                if(nowx && a[nowx - 1][nowy] && !visited[nowx - 1][nowy]) q.emplace(nowx - 1, nowy);
                if(nowy && a[nowx][nowy - 1] && !visited[nowx][nowy - 1]) q.emplace(nowx, nowy - 1);
                if(nowx < n - 1 && a[nowx + 1][nowy] && !visited[nowx + 1][nowy]) q.emplace(nowx + 1, nowy);
                if(nowy < m - 1 && a[nowx][nowy + 1] && !visited[nowx][nowy + 1]) q.emplace(nowx, nowy + 1);
                if(nowx && nowy && a[nowx - 1][nowy - 1] && !visited[nowx - 1][nowy - 1]) q.emplace(nowx - 1, nowy - 1);
                if(nowx && nowy < m - 1 && a[nowx - 1][nowy + 1] && !visited[nowx - 1][nowy + 1]) q.emplace(nowx - 1, nowy + 1);
                if(nowx < n - 1 && nowy < m - 1 && a[nowx + 1][nowy + 1] && !visited[nowx + 1][nowy + 1]) q.emplace(nowx + 1, nowy + 1);
                if(nowx < n - 1 && nowy && a[nowx + 1][nowy - 1] && !visited[nowx + 1][nowy - 1]) q.emplace(nowx + 1, nowy - 1);
            }
        }
    }
    cout << cnt;
}