#include <stdio.h>
using ll = long long;
int main() {
    ll n;
    scanf("%lld", &n);
    ll cnt = 0;
    if(n == 1) {
        printf("koosaga");
        return 0;
    }
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) { n /= i; cnt++; }
        if(cnt > 2) {
            printf("koosaga");
            return 0;
        }
    }
    if(n != 1) cnt++;
    if(cnt != 2) {
        printf("koosaga");
        return 0;
    }
    printf("cubelover");
}