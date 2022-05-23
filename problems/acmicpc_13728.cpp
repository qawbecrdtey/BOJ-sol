#include <cstdio>
#include <numeric>
using ll = long long;
constexpr ll M = 1000000007;
int main() {
    int n; scanf("%d", &n);
    auto *a = new ll[n + 2];
    a[0] = 0; a[1] = 1;
    for(int i = 2; i < n + 2; i++) a[i] = (a[i - 1] + a[i - 2]) % M;
    ll sum = 0;
    for(int i = 2; i < n + 2; i++) {
        sum = (sum + a[std::gcd(i, n + 1)]) % M;
    } printf("%lld", sum);
}