#include <stdio.h>
using ll = long long;
int main() {
    ll m, M;
    scanf("%lld%lld", &m, &M);
    auto a = new bool[M - m + 1]();
    for(ll i = 2; i * i <= M; i++) {
        ll x = (M / (i * i)) * (i * i);
        while(x >= m) {
            a[x - m] = true;
            x -= i * i;
        }
    }
    ll cnt = 0;
    for(ll i = 0; i <= M - m; i++) {
        if(!a[i]) cnt++;
    }
    printf("%lld", cnt);
}