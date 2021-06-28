#include <stdio.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j != m - 1) printf("%d ", cnt++);
            else printf("%d\n", cnt++);
        }
    }
}