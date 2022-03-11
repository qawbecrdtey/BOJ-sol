#include <cstdio>
int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    a += b; int res = 0;
    while(a >= c) {
        res += a / c;
        a = (a / c) + (a % c);
    } printf("%d", res);
}