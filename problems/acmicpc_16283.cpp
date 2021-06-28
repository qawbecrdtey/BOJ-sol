#include <stdio.h>
int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a == b && c != 2) { printf("-1"); return 0; }
    for(int i = 1; i < c; i++) {
        if(a * i + b * (c - i) == d) {
            printf("%d %d", i, c - i);
            return 0;
        }
    }
    printf("-1");
}