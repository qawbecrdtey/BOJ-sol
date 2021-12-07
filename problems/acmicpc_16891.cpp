#include <stdio.h>
using ld = long double;
int main() {
    int n; scanf("%d", &n);
    ld const m1 = 1, m2 = n * n;
    ld v1 = 0, v2 = -1;
    int cnt = 0;
    while(v1 > v2) {
        ld u1 = v1, u2 = v2;
        v1 = ((m1 - m2) * u1 + (2 * m2) * u2) / (m1 + m2);
        v2 = ((2 * m1) * u1 - (m1 - m2) * u2) / (m1 + m2);
        cnt++;
        if(v1 < 0) {
            v1 = -v1;
            cnt++;
        }
    }
    printf("%d", cnt);
}