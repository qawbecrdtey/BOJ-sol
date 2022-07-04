#include <cstdio>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    if(n % 3 && m % 3) printf("NO");
    else printf("YES");
}