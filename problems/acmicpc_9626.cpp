#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, u, l, r, d; cin >> n >> m >> u >> l >> r >> d;
    int const R = n + u + d;
    int const C = m + l + r;
    auto a = new char*[R];
    for(int i = 0; i < R; i++) {
        a[i] = new char[C + 1];
        for(int j = 0; j < C; j++) {
            a[i][j] = ((i + j) & 1) ? '.' : '#';
        }
        a[i][C] = 0;
    }
    auto s = new char[m + 1];
    for(int i = u; i < u + n; i++) {
        cin >> s;
        for(int j = l; j < l + m; j++) {
            a[i][j] = s[j - l];
        }
    }
    for(int i = 0; i < R; i++) {
        cout << a[i] << '\n';
    }
}
