#include <stdio.h>
using ll = long long;
int main() {
    ll n;
    scanf("%lld", &n);
    auto a = new ll[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    ll b, c;
    scanf("%lld%lld", &b, &c);
    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= b) {
            res++;
            continue;
        }
        res += 2 + (a[i] - b - 1) / c;
    }
    printf("%lld", res);
    delete[] a;
}