#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        a[i] = new int[n + 1]();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int res = a[1][1];
    for(int k = 1; k <= n; k++) {
        for(int i = k; i <= n; i++) {
            for(int j = k; j <= n; j++) {
                auto const sum = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
                if(sum > res) res = sum;
            }
        }
    }
    printf("%d", res);
    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}