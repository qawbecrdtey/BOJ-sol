#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
inline ll sum(ll a[6]) { return a[0] + a[1] + a[2] + a[3] + a[4] + a[5]; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        ll a[6];
        ll b[6];
        for(int i = 0; i < 6; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        int res = 1;
        while(sum(a) <= n) {
            for(int i = 0; i < 6; i++) {
                b[i] += a[(i + 1) % 6] + a[(i + 3) % 6] + a[(i + 5) % 6];
            }
            copy_n(b, 6, a);
            res++;
        }
        cout << res << '\n';
    }
}