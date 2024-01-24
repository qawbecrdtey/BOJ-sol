#include <iostream>
using namespace std;
using ll = long long;
inline ll sqrt(ll n) {
    if(n < 2) return n;
    ll l = 0, r = n;
    ll res = 0;
    while(l < r) {
        ll const m = (l + r) >> 1;
        ll const M = m * m;
        if(M == n) return m;
        if(M < n) res = m, l = m + 1;
        else r = m;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll res = 0;
    for(ll x = 1; x * x * x * x * x + 3 < n; x++) {
        auto const X = x * x * x * x * x;
        for(ll y = 1; X + y * y * y * y + 2 < n; y++) {
            auto const Y = y * y * y * y;
            for(ll z = 1; X + Y + z * z * z + 1 < n; z++) {
                auto const Z = z * z * z;
                auto const N = n - X - Y - Z - 1;
                res += sqrt(N);
            }
        }
    }
    cout << res;
}