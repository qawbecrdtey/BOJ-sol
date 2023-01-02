#include <cstdio>
int main() {
    long long a, b, x{}, y{}; while(scanf("%lld.%lld", &a, &b) != EOF) x += a, y += b; printf("%lld.%02lld", x + y / 100, y % 100);
}