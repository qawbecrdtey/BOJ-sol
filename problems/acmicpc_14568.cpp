#include <stdio.h>
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = i + 3; j <= n - i; j++) {
            for(int h = 1; h <= n - i - j; h += 2) {
                if(i + j + h == n) cnt++;
            }
        }
    }
    printf("%d", cnt);
}