#include <cassert>
#include <iostream>
#include <numeric>
#include <optional>
using namespace std;
using ll = long long;
inline optional<ll> is_square(ll n) {
    if(n < 0) return nullopt;
    if(n < 2) return n;
    ll l = 1, r = n, res = 1;
    while(l < r) {
        ll m = min((l + r) / 2, 1000000000LL);
        if(m * m == n) return m;
        if(m * m < n) {
            res = m;
            l = m + 1;
        }
        else r = m;
    }
    if(res * res == n) return res;
    if(l * l == n) return l;
    return nullopt;
}
inline void normalize(pair<ll, ll> &p) {
    ll const g = gcd(p.first, p.second);
    p.first /= g, p.second /= g;
    if(p.second < 0) {
        p.first = -p.first;
        p.second = -p.second;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto opt = is_square(5 * n * n + 10 * n + 1);
    if(opt == nullopt) {
        cout << -1;
        return 0;
    }
    pair<ll, ll> r1{ -n - 1 + *opt, 2 * n }, r2{ -n - 1 - *opt, 2 * n };
    normalize(r1); normalize(r2);
    if(r1.second * r2.second != n) {
        r1.second *= n / (r1.second * r2.second);
        assert(r1.second * r2.second == n);
    }
    cout << r1.second << ' ' << -r1.first << ' ' << r2.second << ' ' << -r2.first;
}