#include <cstdio>
int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    auto *a = new char[m + 1];
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < m * k; l++) {
                printf("%c", a[l / k]);
            } if(j != k - 1) printf("\n");
        } if(i != n - 1) printf("\n");
    }
    delete[] a;
}