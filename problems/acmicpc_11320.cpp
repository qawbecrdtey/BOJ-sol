#include <stdio.h>
int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int c = (a - 1) / b + 1;
        printf("%d\n", c * c);
    }
}