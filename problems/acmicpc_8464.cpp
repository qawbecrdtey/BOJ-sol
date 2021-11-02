#include <cstdio>
using ll = long long;
ll count(ll const *mobius, ll n) {
    ll sum = 0;
    for(ll i = 1; i * i <= n; i++) {
        sum += mobius[i] * (n / (i * i));
    }
    return n - sum;
}
int main() {
    ll n;
    auto mobius = new ll[1000001]();
    mobius[1] = 1;
    for(ll i = 1; i <= 1000000; i++) {
        if(mobius[i]) {
            for(ll j = (i << 1); j <= 1000000; j += i) {
                mobius[j] -= mobius[i];
            }
        }
    }
    scanf("%lld", &n);
    ll l = 4, r = 8;
    while(count(mobius, r) <= n) l <<= 1, r <<= 1;
    while(l < r) {
        auto const m = (l + r) / 2;
        auto const c = count(mobius, m);
        if(c >= n) r = m;
        else l = m + 1;
    }
    printf("%lld", l);
}