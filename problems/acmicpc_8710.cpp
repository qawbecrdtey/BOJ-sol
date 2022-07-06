#include <cstdio>
int main() {
    long long k, w, m;
    scanf("%lld%lld%lld", &k, &w, &m);
    printf("%lld", (w - k + m - 1) / m);
}