#include <array>
#include <cstdio>
using ll = long long;
using arr = std::array<ll, 10>;
inline void add(arr &x, arr const &y) { for(int i = 0; i < 10; i++) x[i] += y[i]; }
arr zero(ll n, ll k) {
    if(k == 1) {
        arr res;
        ll i;
        for(i = 0; i <= n; i++) res[i] = 1;
        for(; i < 10; i++) res[i] = 0;
        return res;
    }
    auto const c = zero(k - 1, k / 10);
    arr res{};
    for(ll i = 0; i <= n; i += k) {
        if(i + k > n) {
            res[i / k] += n - i + 1;
            add(res, zero(n - i, k / 10));
            return res;
        }
        res[i / k] += k;
        add(res, c);
    }
    return res;
}
arr nonzero(ll n, ll k) {
    if(k == 1) {
        arr res;
        ll i;
        for(i = 0; i <= n; i++) res[i] = 1;
        for(; i < 10; i++) res[i] = 0;
        return res;
    }
    if(n < k) return nonzero(n, k / 10);
    auto const c = zero(k - 1, k / 10);
    auto res = nonzero(k - 1, k / 10);
    for(ll i = k; i <= n; i += k) {
        if(i + k > n) {
            res[i / k] += n - i + 1;
            add(res, zero(n - i, k / 10));
            return res;
        }
        res[i / k] += k;
        add(res, c);
    }
    return res;
}
int main() {
    ll n, k = 1;
    scanf("%lld", &n);
    while(k <= n) k *= 10;
    auto a = nonzero(n, k);
    for(int i = 0; i < 10; i++) {
        printf("%lld ", a[i] - (!i));
    }
}