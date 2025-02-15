#include <iostream>
#include <queue>
using namespace std;
bool dfs(int const n, int const m, int const *const *const a, bool *const *const visited, int const x, int const y) {
    visited[x][y] = true;
    if(x == n - 1 && y == m - 1) return true;
    if(x < n - 1 && a[x + 1][y] && !visited[x + 1][y] && dfs(n, m, a, visited, x + 1, y)) return true;
    if(y < m - 1 && a[x][y + 1] && !visited[x][y + 1] && dfs(n, m, a, visited, x, y + 1)) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> m >> n;
    auto a = new int*[n];
    auto visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        visited[i] = new bool[m]();
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if(dfs(n, m, a, visited, 0, 0)) cout << "Yes";
    else cout << "No";
}
