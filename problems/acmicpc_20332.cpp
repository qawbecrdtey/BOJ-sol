#include <cstdio>
int main() {
    long long n, v{}; scanf("%lld", &n); while(n--) {
        int x; scanf("%d", &x); v += x;
    } if(v % 3) printf("no"); else printf("yes");
}