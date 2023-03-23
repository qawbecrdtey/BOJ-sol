#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n; auto a = new ll[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(auto p = lower_bound(a, a + n, (a[i] << 1) - a[j]); p != a + n && *p == (a[i] << 1) - a[j]) {
                    cnt++;
                }
            }
        } cout << cnt << '\n';
        delete[] a;
    }
}