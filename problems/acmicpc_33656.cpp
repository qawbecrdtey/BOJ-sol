#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new char*[n];
    auto visited = new bool*[n];
    pair<int, int> s;
    for(int i = 0; i < n; i++) {
        a[i] = new char[m + 1];
        visited[i] = new bool[m]();
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'S') s = {i, j};
        }
    }
    queue<pair<int, int>> q;
    q.emplace(std::move(s));
    int res = 0;
    while(!q.empty()) {
        auto const [nowx, nowy] = q.front(); q.pop();
        if(visited[nowx][nowy]) continue;
        visited[nowx][nowy] = true;
        res++;
        if(nowx && a[nowx - 1][nowy] == '#' && !visited[nowx - 1][nowy]) q.emplace(nowx - 1, nowy);
        if(nowy && a[nowx][nowy - 1] == '#' && !visited[nowx][nowy - 1]) q.emplace(nowx, nowy - 1);
        if(nowx < n - 1 && a[nowx + 1][nowy] == '#' && !visited[nowx + 1][nowy]) q.emplace(nowx + 1, nowy);
        if(nowy < m - 1 && a[nowx][nowy + 1] == '#' && !visited[nowx][nowy + 1]) q.emplace(nowx, nowy + 1);
    }
    cout << res;
}
