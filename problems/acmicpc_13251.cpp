#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(15);
    cout << fixed;
    int m, n = 0, k; cin >> m;
    auto a = new int[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i]; n += a[i];
    } cin >> k;
    double res = 0;
    for(int i = 0; i < m; i++) {
        double d = 1;
        if(a[i] >= k) {
            for (int j = 0; j < k; j++) {
                d *= (double) (a[i] - j) / (n - j);
            }
            res += d;
        }
    } cout << res;
}