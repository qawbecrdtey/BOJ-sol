#include <cstdio>
inline void draw(int **a, int x, int y, int lv, int val) {
    for(int i = 0; i < lv; i++) {
        a[x][++y] = val++;
    }
    for(int i = 0; i < lv; i++) {
        a[++x][y] = val++;
    }
    for(int i = 0; i < lv; i++) {
        a[x][--y] = val++;
    }
    for(int i = 0; i < lv; i++) {
        a[--x][y] = val++;
    }
}
int main() {
    int n, k; scanf("%d%d", &n, &k);
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    a[n / 2][n / 2] = 1;
    for(int i = n / 2, lv = 2, val = 2; i > 0; i--) {
        draw(a, i - 1, i - 1, lv, val);
        val += 4 * lv;
        lv += 2;
    }
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == k) x = i, y = j;
            printf("%d ", a[i][j]);
        } printf("\n");
    }
    printf("%d %d", x + 1, y + 1);
}