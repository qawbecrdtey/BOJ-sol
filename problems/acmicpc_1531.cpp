#include <stdio.h>
int main() {
    int canvas[101][101] = {};
    int n, m;
    scanf("%d%d", &n, &m);
    while(n--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for(int i = a; i <= c; i++) {
            for(int j = b; j <= d; j++) {
                canvas[i][j]++;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            cnt += (canvas[i][j] > m);
        }
    }
    printf("%d", cnt);
}