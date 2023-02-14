#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using namespace std;
using ull = uint64_t;
ull get_random() {
    static random_device rd;
    static mt19937_64 gen(rd());
    static uniform_int_distribution<ull> dist(2, 1LL << 63);
    return dist(gen);
}
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
    for(ull a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
        if(n == a) return true;
        if(check_composite(n, a, d, r)) return false;
    } return true;
}
inline ull rho(ull n, ull x0, ull c) {
    if(!(n & 1)) return 2;
    ull x = x0, y = x0;
    ull g = 1;
    auto const f = [n, c](ull x) -> ull {
        return static_cast<ull>((static_cast<__uint128_t>(x) * x % n + c) % n);
    };
    while(g == 1) {
        x = f(x);
        y = f(f(y));
        g = gcd(abs(static_cast<int64_t>(static_cast<__int128_t>(x) - y)), n);
    } return g;
}
vector<ull> factorize(ull n) {
    vector<ull> res{ n };
    if(n == 1 || is_prime(n)) return res;
    ull d;
    do d = rho(n, get_random() % n, get_random() % n); while(d == n);
    auto const factor1 = factorize(d);
    auto const factor2 = factorize(n / d);
    res.resize(factor1.size() + factor2.size());
    merge(factor1.begin(), factor1.end(), factor2.begin(), factor2.end(), res.begin());
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ull n; cin >> n;
    auto const factor = factorize(n);
    for(ull p : factor) cout << p << '\n';
}