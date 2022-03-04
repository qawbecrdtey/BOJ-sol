#include <stdio.h>
int main() {
    int a, b, c;
    while(true) {
        scanf("%d%d%d", &a, &b, &c);
        if(!a && !b && !c) return 0;
        int num = a * (c - b), den = b * c;
        int h = num / den;
        num %= den; num *= 60;
        int m = num / den;
        num %= den; num *= 60;
        int s = num / den + (num % den >= den / 2);
        printf("%d:%02d:%02d\n", h, m, s);
    }
}