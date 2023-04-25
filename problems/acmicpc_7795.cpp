#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto a = new int[n];
        auto b = new int[m];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        std::size_t res = 0;
        for(int i = 0; i < m; i++) {
            auto const p = upper_bound(a, a + n, b[i]);
            res += (a + n) - p;
        } cout << res << '\n';
        delete[] b;
        delete[] a;
    }
}