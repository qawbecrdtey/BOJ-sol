#include <algorithm>
#include <cstdio>
using ll = long long;
constexpr ll M = 1000000007;
ll f(ll ***dp, ll n, ll l, ll r) {
	if(dp[n][l][r] != -1) return dp[n][l][r];
	if(!l || !r) return dp[n][l][r] = 0;
	if(n == 1) return dp[n][l][r] = (l == 1 && r == 1);
	if(n == 2) return dp[n][l][r] = (l == 1 && r == 2) || (l == 2 && r == 1);
	return dp[n][l][r] = (f(dp, n - 1, l - 1, r) + f(dp, n - 1, l, r - 1) +  (n - 2) * f(dp, n - 1, l, r)) % M;
}
int main() {
	ll n, l, r; scanf("%lld%lld%lld", &n, &l, &r);
	auto dp = new ll**[n + 1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new ll*[l + 1];
		for(int j = 0; j <= l; j++) {
			dp[i][j] = new ll[r + 1];
			std::fill(dp[i][j], dp[i][j] + r + 1, -1);
		}
	}
	printf("%lld", f(dp, n, l, r));
}