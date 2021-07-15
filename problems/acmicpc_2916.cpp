#include <stdio.h>
int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int g = 360;
    while(n--) {
        int x;
        scanf("%d", &x);
        g = gcd(g, x);
    }
    while(k--) {
        int x;
        scanf("%d", &x);
        printf(x % g ? "NO\n" : "YES\n");
    }
}