#include <cstdio>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int res = 0;
    while(a) {
        res += a;
        a /= b;
    }
    printf("%d", res);
}