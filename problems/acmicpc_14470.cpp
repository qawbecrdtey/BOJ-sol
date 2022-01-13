#include <stdio.h>
int main() {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int res = 0;
    for(int i = a; i < b; i++) {
        if(i < 0) res += c;
        else if(i > 0) res += e;
        else res += d + e;
    }
    printf("%d", res);
}