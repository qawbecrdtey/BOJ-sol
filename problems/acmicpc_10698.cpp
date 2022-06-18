#include <cstdio>
int main() {
    int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++) {
        int a, b, c; char d[2];
        scanf("%d %s %d = %d", &a, d, &b, &c);
        printf("Case %d: %s\n", tt, ((*d == '+') ? ((a + b == c) ? "YES" : "NO") : ((a - b == c) ? "YES" : "NO")));
    }
}