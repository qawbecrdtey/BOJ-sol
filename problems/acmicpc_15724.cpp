#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new ll*[n + 1];
    for(int i = 0; i <= n; i++) {
        a[i] = new ll[m + 1]();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    int q; cin >> q; while(q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << a[x2][y2] - a[x2][y1] - a[x1][y2] + a[x1][y1] << '\n';
    }
}