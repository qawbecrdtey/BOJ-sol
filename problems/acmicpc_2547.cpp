#include <stdio.h>
int main() {
    int t; scanf("%d", &t); while(t--) {
        int n; scanf("%d", &n);
        __int128 cnt = 0;
        for(int i = 0; i < n; i++) {
            unsigned long long x; scanf("%llu", &x);
            cnt += x;
        }
        printf(cnt % n ? "NO\n" : "YES\n");
    }
}