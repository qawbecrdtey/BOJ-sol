#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int res = 250;
    while(b < a) b += c, res += 100;
    printf("%d", res);
}