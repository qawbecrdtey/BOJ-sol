#include <stdio.h>
using ull = unsigned long long;
inline ull calc(ull n) {
    ull l = 1, r = (n > 200000001 ? 200000001 : n);
    while(l < r) {
        ull const m = (l + r) / 2;
        ull const x = m * (m + 1) / 2;
        if(x < n) l = m + 1;
        else r = m;
    } return l;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ull n;
        scanf("%llu", &n);
        printf("%llu\n", calc(n + 1) - 1);
    }
}