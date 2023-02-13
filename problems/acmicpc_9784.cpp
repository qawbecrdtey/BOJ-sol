#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        int n, p, q; cin >> n >> p >> q;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int res = 0;
        for(int sum = 0; res < n && res < p; res++) {
            if(sum + a[res] > q) break;
            sum += a[res];
        } cout << res << '\n';
    }
}