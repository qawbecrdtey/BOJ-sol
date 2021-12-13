#include <stdio.h>
int main() {
    int a, b, c, d, e, f;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &d, &e, &f);
    while(f < c) e--, f += 60;
    while(e < b) d--, e += 60;
    while(d < a) d += 24;
    if(d - a == 0 && e - b == 0 && f - c == 0) d += 24;
    printf("%02d:%02d:%02d", d - a, e - b, f - c);
}