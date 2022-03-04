#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    auto b = new long long[n];
    auto a = new long long[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for(int i = n - 1; i; i--) {
        a[i] = b[i] * (i + 1) - b[i - 1] * i;
    } a[0] = b[0];
    for(int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
}