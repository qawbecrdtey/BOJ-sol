#include <stdio.h>
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(t - x < 0) {
            printf("%d", i);
            return 0;
        }
        t -= x;
    }
    printf("%d", n);
}