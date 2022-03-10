#include <cstdio>
int main() {
    int n; scanf("%d", &n);
    int a[51]{};
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    for(int i = 50; i >= 0; i--) {
        if(a[i] == i) {
            printf("%d", i);
            return 0;
        }
    } printf("-1");
}