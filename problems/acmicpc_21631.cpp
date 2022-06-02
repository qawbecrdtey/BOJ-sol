#include <cstdio>
int main() {
    long long a, b; scanf("%lld%lld", &a, &b);
    printf("%lld", ((a + 1) > b ? b : (a + 1)));
}