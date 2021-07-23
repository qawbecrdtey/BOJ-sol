#include <stdio.h>
int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        int max = -1000000;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
            if(max < sum) max = sum;
            if(sum < 0) sum = 0;
        }
        printf("%d\n", max);
    }
}