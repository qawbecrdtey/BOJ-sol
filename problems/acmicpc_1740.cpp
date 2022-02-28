#include <stdio.h>
int main() {
    unsigned long long n, x = 0, c = 1; scanf("%llu", &n);
    while(n) {
        if(n & 1) x += c;
        c *= 3; n >>= 1;
    } printf("%llu", x);
}