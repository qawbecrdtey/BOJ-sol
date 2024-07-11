#include <iostream>
#include <queue>
using namespace std;
bool find_cycle(int const n, int const m, char const color, char const *const *const a, bool *const *const visited, int const nowx, int const nowy, int const prevx, int const prevy) {
    if(visited[nowx][nowy]) return true;
    visited[nowx][nowy] = true;
    if(auto const nextx = nowx - 1; 0 <= nextx && prevx != nextx && a[nextx][nowy] == color && find_cycle(n, m, color, a, visited, nextx, nowy, nowx, nowy)) return true;
    if(auto const nexty = nowy - 1; 0 <= nexty && prevy != nexty && a[nowx][nexty] == color && find_cycle(n, m, color, a, visited, nowx, nexty, nowx, nowy)) return true;
    if(auto const nextx = nowx + 1; nextx < n && prevx != nextx && a[nextx][nowy] == color && find_cycle(n, m, color, a, visited, nextx, nowy, nowx, nowy)) return true;
    if(auto const nexty = nowy + 1; nexty < m && prevy != nexty && a[nowx][nexty] == color && find_cycle(n, m, color, a, visited, nowx, nexty, nowx, nowy)) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new char*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new char[m + 1];
        visited[i] = new bool[m + 1]();
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) continue;
            if(find_cycle(n, m, a[i][j], a, visited, i, j, -1, -1)) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}