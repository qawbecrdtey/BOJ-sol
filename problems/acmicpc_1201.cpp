#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    if(n < m + k - 1 || n > m * k) {
        cout << -1;
        return 0;
    }
    auto a = new int[m];
    a[0] = k;
    int rest = n - k;
    for(int i = 1; i < m; i++) {
        a[i] = rest / (m - i) + (rest % (m - i) != 0);
        rest -= a[i];
        a[i] += a[i - 1];
    }
    for(int i = 0; i < m; i++) {
        for(int j = a[i]; j && (!i || j > a[i - 1]); j--) {
            cout << j << ' ';
        }
    }
}