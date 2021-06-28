#include <stdio.h>
int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int n;
        scanf("%d", &n);
        printf("Pairs for %d:", n);
        for(int i = 1; i + i < n; i++) {
            if(i == 1) printf(" %d %d", i, n - i);
            else printf(", %d %d", i, n - i);
        }
        printf("\n");
    }
}