#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto in = new string[n];
    for(int i = 0; i < n; i++) cin >> in[i];
    auto out = new char*[n << 1];
    for(int i = 0; i < (n << 1); i++) out[i] = new char[m << 1];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            out[i][j] = out[i][2 * m - j - 1] = out[2 * n - i - 1][j] = out[2 * n - i - 1][2 * m - j - 1] = in[i][j];
        }
    }
    int x, y; cin >> x >> y;
    out[x - 1][y - 1] = (char)('.' + '#' - out[x - 1][y - 1]);
    for(int i = 0; i < (n << 1); i++) {
        for(int j = 0; j < (m << 1); j++) {
            cout << out[i][j];
        } cout << '\n';
    }
}