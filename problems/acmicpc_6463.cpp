#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll n; while(scanf("%lld", &n) != EOF) {
        printf("%5lld -> ", n);
        __int128_t x = 1;
        for(ll i = 1; i <= n; i++) {
            x = x * i; while(x % 10 == 0) x /= 10;
            x = x % 1000000000000000;
        } printf("%lld\n", (ll)(x % 10));
    }
}