#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, k, x, y; cin >> n >> k >> x >> y;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n < k + 2) {
            cout << "NO\n";
            goto END;
        }
        sort(a, a + n);
        if(x >= y) {
            if(a[n - 2] >= x && (k == 0 || a[n - k - 2] >= y)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if((k == 0 || a[n - k] >= y) && a[n - k - 2] >= x) cout << "YES\n";
            else cout << "NO\n";
        }
    END:delete[] a;
    }
}