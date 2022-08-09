#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	auto a = new int[t];
	int m = 0;
	for(int i = 0; i < t; i++) {
		cin >> a[i];
		if(m < a[i]) m = a[i];
	}
	auto dp = new ll[m + 6]();
	dp[0] = dp[1] = 1;
	dp[2] = dp[3] = 2;
	dp[4] = dp[5] = 3;
	for(int i = 6; i <= m; i++) {
		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
	}
	for(int i = 0; i < t; i++) {
		cout << dp[a[i]] << '\n';
	}
}