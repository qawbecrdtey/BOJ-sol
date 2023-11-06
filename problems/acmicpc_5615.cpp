#pragma GCC optimize("O3")
#include <cstdint>
#include <iostream>
using namespace std;
using ull = uint64_t;
inline ull power(ull n, ull p, ull m) {
    ull res = 1;
    n %= m;
    while(p) {
        if(p & 1) res = static_cast<ull>(static_cast<__uint128_t>(res) * n % m);
        n = static_cast<ull>(static_cast<__uint128_t>(n) * n % m);
        p >>= 1;
    } return res;
}
// n - 1 = d * 2^s
inline bool check_composite(ull n, ull a, ull d, ull s) {
    auto x = power(a, d, n);
    if(x == 1 || x == n - 1) return false;
    for(ull r = 1; r < s; r++) {
        x = static_cast<ull>(static_cast<__uint128_t>(x) * x % n);
        if(x == n - 1) return false;
    } return true;
}
inline bool is_prime(ull n) {
    if(n < 2) return false;
    ull r = 0;
    ull d = n - 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    for(ull a : { 2, 3, 5, 7, 11, 13, 17 }) {
        if(n == a) return true;
        if(check_composite(n, a, d, r)) return false;
    } return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ull t; cin >> t;
    int res = 0;
    while(t--) {
        ull n; cin >> n;
        res += is_prime(n * 2 + 1);
    }
    cout << res;
}