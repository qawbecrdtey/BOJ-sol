#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    auto a = new ll[k];
    for(ll i = 0; i < k; i++) cin >> a[i];
    ll res = 0;
    for(ll i = 1; i < (1 << k); i++) {
        ll mul = 1;
        bool odd = false;
        for(ll j = 0; j < k && mul <= n; j++) {
            if(i & (1 << j)) {
                mul = lcm(mul, a[j]);
                odd = !odd;
            }
        } if(mul > n) continue;
        if(odd) res += n / mul;
        else res -= n / mul;
    } cout << res;
}