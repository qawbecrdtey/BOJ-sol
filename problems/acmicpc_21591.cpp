#include <cstdio>
int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(c < a - 1 && d < b - 1) printf("1");
    else printf("0");
}