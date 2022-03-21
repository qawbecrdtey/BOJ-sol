#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        printf("Case %d:\n", tt);
        int n; scanf("%d", &n);
        for(int i = 1; i <= 6; i++) {
            for(int j = i; j <= 6; j++) {
                if(i + j == n) {
                    printf("(%d,%d)\n", i, j);
                }
            }
        }
    }
}