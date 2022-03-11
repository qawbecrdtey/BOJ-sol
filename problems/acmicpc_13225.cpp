#include <cstdio>
int main() {
    int t; scanf("%d", &t); while(t--) {
        int n; scanf("%d", &n);
        printf("%d ", n);
        int cnt = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                cnt++;
                if(i * i != n) cnt++;
            }
        } printf("%d\n", cnt);
    }
}