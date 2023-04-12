#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, q; cin >> n >> q;
    auto a = new ll[n];
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while(q--) {
        ll x, y; cin >> x >> y;
        switch(x) {
            case 1: cout << (a + n - lower_bound(a, a + n, y)) << '\n'; break;
            case 2: cout << (a + n - upper_bound(a, a + n, y)) << '\n'; break;
            case 3: {
                ll z; cin >> z;
                cout << (upper_bound(a, a + n, z) - lower_bound(a, a + n, y)) << '\n';
            } break;
            default: __builtin_unreachable();
        }
    }
}