#include <stdio.h>
using ll = long long;
constexpr ll p = 1000000007;
ll mul(ll a, ll b) { return (a * b) % p; }
ll add(ll a, ll b, ll c) { return (a + b + c) % p; }
ll max(ll a, ll b) { return a > b ? a : b; }
int main() {
    int n;
    scanf("%d", &n);
    auto a = new ll[n + 1];
    auto b = new ll[n];
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    ll *dp[3];
    for(auto &i : dp) i = new ll[n + 1]();
    dp[0][1] = a[1];
    dp[1][1] = 0;
    dp[2][1] = b[1];
    for(int i = 2; i <= n; i++) {
        dp[0][i] = add(mul(dp[0][i - 1], a[i]), mul(dp[1][i - 1], a[i]), mul(dp[2][i - 1], a[i]));
        dp[1][i] = add(mul(dp[0][i - 1], b[i - 1]), mul(dp[1][i - 1], b[i - 1]), mul(dp[2][i - 1], max(b[i - 1] - 1, 0)));
        if(i != n) dp[2][i] = add(mul(dp[0][i - 1], b[i]), mul(dp[1][i - 1], b[i]), mul(dp[2][i - 1], b[i]));
    }
    printf("%lld", add(dp[0][n], dp[1][n], dp[2][n]));
    for(auto &i : dp) delete[] i;
    delete[] a;
    delete[] b;
}