#include <cstdio>
using ll = long long;
static constexpr ll M = 1000007;
int main() {
	ll a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	ll dp[401][401]{};
	for(int i = 0; i < 401; i++) {
		for(int j = 0; j <= i; j++) {
			if(!j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
		}
	}
	printf("%lld", (dp[c + d - 2][d - 1] * dp[a + b - c - d][a - c]) % M);
}