#include <iostream>
using namespace std;
pair<int, int> nextd[8] {{1, 2}, {1, -2}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x, y, k; cin >> n >> x >> y >> k; x--; y--;
    auto a = new double*[n];
    auto b = new double*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new double[n]();
        b[i] = new double[n];
    }
    a[x][y] = 1.0;
    while(k--) {
        for(int i = 0; i < n; i++) {
            fill(b[i], b[i] + n, 0.0);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(auto const [dx, dy] : nextd) {
                    if(i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n) continue;
                    b[i + dx][j + dy] += 0.125 * a[i][j];
                }
            }
        }
        swap(a, b);
    }
    double res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res += a[i][j];
        }
    }
    cout.precision(12);
    cout << fixed << res;
}
