#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(3);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);
        auto p = lower_bound(a, a + n, sum / n + 1);
        cout << fixed << ((a + n - p) * 100.0 + 1e-9) /  n  << "%\n";
        delete[] a;
    }
}