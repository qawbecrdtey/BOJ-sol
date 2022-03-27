#include <iostream>
#include <string>
using namespace std;
using ll = long long;
constexpr ll M = 1000000009;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	auto dp = new ll*[n];
	for(int i = 0; i < n; i++) {
		dp[i] = new ll[m];
		fill(dp[i], dp[i] + m, 1);
		cin >> a[i];
	} dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			switch(a[i][j]) {
				case 'B':
					dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % M;
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % M;
					break;
				case 'S':
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % M;
					break;
				case 'E':
					dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % M;
					break;
				case 'X': break;
				default: __builtin_unreachable();
			}
		}
	}
	printf("%lld", dp[n - 1][m - 1]);
}