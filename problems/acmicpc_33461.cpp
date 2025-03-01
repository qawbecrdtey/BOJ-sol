#include <iostream>
using namespace std;
pair<int, int> const d[] {{1,2},{1,-2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,-1},{-2,1}};
inline void queen(int const n, bool *const *const a, int const x, int const y) noexcept {
    for(int i = 0; i < n; i++) {
        a[i][y] = a[x][i] = true;
        if(y - x + i >= 0 && y - x + i < n) a[i][y - x + i] = true;
        if(x + y - i >= 0 && x + y - i < n) a[x + y - i][i] = true;
    }
}
inline void rook(int const n, bool *const *const a, int const x, int const y) noexcept {
    for(int i = 0; i < n; i++) {
        a[i][y] = a[x][i] = true;
    }
}
inline void night(int const n, bool *const *const a, int const x, int const y) noexcept {
    a[x][y] = true;
    for(auto const [dx, dy] : d) {
        if(x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n) {
            a[x + dx][y + dy] = true;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new bool*[n];
    for(int i = 0; i < n; i++) a[i] = new bool[n]();
    while(m--) {
        char c[2]; int x, y; cin >> c >> x >> y; x--; y--;
        switch(*c) {
            case 'Q': queen(n, a, x, y); break;
            case 'R': rook(n, a, x, y); break;
            case 'N': night(n, a, x, y); break;
            default: __builtin_unreachable();
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res += a[i][j];
        }
    }
    cout << res;
}
