#include <array>
#include <iostream>
#include <string>
using namespace std;
static constexpr array<int, 2> near[8] { {{1, 0}}, {{1, 1}}, {{0, 1}}, {{-1, 1}}, {{-1, 0}}, {{-1, -1}}, {{0, -1}}, {{1, -1}} };
bool peek(string const *a, int const n, int const m, array<int, 2> const pos, array<int, 2> const dir) {
    int const x = pos[0] + dir[0];
    int const y = pos[1] + dir[1];
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return a[x][y] == '*';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; while(cin >> n >> m) {
        if(!n && !m) return 0;
        auto const a = new string[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '*') {
                    cout << '*';
                    continue;
                }
                int res = 0;
                for(auto const dir : near) {
                    res += peek(a, n, m, {{ i, j }}, dir);
                }
                cout << res;
            }
            cout << '\n';
        }
        delete[] a;
    }
}