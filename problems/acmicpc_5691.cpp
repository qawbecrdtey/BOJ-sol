#include <stdio.h>
int main() {
    long long a, b;
    while(true) {
        scanf("%lld%lld", &a, &b);
        if(!a && !b) return 0;
        printf("%lld\n", 2 * a - b);
    }
}