#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt += (i != x);
    }
    printf("%d", cnt);
}