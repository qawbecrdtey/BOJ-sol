#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto a = new bool*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new bool[m]();
        visited[i] = new bool[m]();
    }
    while(k--) {
        int x, y; cin >> x >> y;
        a[x - 1][y - 1] = true;
    }
    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!a[i][j]) continue;
            int cnt = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            while(!q.empty()) {
                auto const [nowx, nowy] = q.front(); q.pop();
                if(visited[nowx][nowy]) continue;
                visited[nowx][nowy] = true;
                cnt++;
                if(nowx && !visited[nowx - 1][nowy] && a[nowx - 1][nowy]) q.push({ nowx - 1, nowy });
                if(nowy && !visited[nowx][nowy - 1] && a[nowx][nowy - 1]) q.push({ nowx, nowy - 1 });
                if(nowx < n - 1 && !visited[nowx + 1][nowy] && a[nowx + 1][nowy]) q.push({ nowx + 1, nowy });
                if(nowy < m - 1 && !visited[nowx][nowy + 1] && a[nowx][nowy + 1]) q.push({ nowx, nowy + 1 });
            }
            if(cnt > max) max = cnt;
        }
    }
    cout << max;
}