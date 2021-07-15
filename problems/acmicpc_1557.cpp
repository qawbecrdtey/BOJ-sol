#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 1000000;
ll count(int const *mobius, ll n) {
    ll res = 0;
    for(ll i = 1; i * i <= n; i++) {
        res += mobius[i] * (n / (i * i));
    }
    return res;
}
int main() {
    int mobius[M] = { 0, 1 };
    for(ll i = 1; i < M; i++) {
        if(mobius[i]) {
            for(ll j = (i << 1); j < M; j += i) {
                mobius[j] -= mobius[i];
            }
        }
    }
    ll n;
    scanf("%lld", &n);
    if(n < 4) { printf("%lld", n); return 0; }
    ll l = 4, r = 8;
    while(count(mobius, r) < n) {
        l <<= 1;
        r <<= 1;
    }
    ll res = r++;
    while(l < r) {
        auto const m = (l + r) / 2;
        auto const cnt = count(mobius, m);
        if(cnt == n) {
            res = m;
            r = m;
            continue;
        }
        if(cnt < n) {
            l = m + 1;
            continue;
        }
        r = m;
    }
    printf("%lld", res);
}