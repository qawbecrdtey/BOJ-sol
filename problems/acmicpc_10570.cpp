#include <stdio.h>
int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int n, a[1001] = {};
        scanf("%d", &n);
        while(n--) {
            int x;
            scanf("%d", &x);
            a[x]++;
        }
        int max = 0;
        int maxi = 0;
        for(int i = 1; i <= 1000; i++) {
            if(max < a[i]) {
                max = a[i];
                maxi = i;
            }
        }
        printf("%d\n", maxi);
    }
}