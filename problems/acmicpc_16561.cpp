#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    n /= 3;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; i + j < n; j++) {
            cnt++;
        }
    }
    printf("%d", cnt);
}
