#include <cstdio>
int main() {
    int n; scanf("%d", &n);
    int x = n / 100 + 25, y = n % 100;
    if(x < 100) x = 100, y = 0;
    if(x >= 2000) x = 2000, y = 0;
    printf("%d.%02d", x, y);
}