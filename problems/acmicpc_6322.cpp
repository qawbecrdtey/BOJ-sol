#include <stdio.h>
#include <math.h>
int main() {
    int cnt = 1;
    while(true) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) return 0;
        if(c == -1) {
            printf("Triangle #%d\nc = %.3lf\n\n", cnt++, sqrt((double)a * a + (double)b * b));
            continue;
        }
        if(b == -1) {
            printf("Triangle #%d\n", cnt++);
            if(c <= a) {
                printf("Impossible.\n\n");
                continue;
            }
            printf("b = %.3lf\n\n", sqrt((double)c * c - (double)a * a));
            continue;
        }
        printf("Triangle #%d\n", cnt++);
        if(c <= b) {
            printf("Impossible.\n\n");
            continue;
        }
        printf("a = %.3lf\n\n", sqrt((double)c * c - (double)b * b));
    }
}