#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new string[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		auto dp = new int*[n];
		for(int i = 0; i < n; i++) dp[i] = new int[n]();
		int m = 0;
		for(int i = 0; i < n; i++) {
			dp[i][0] = (a[i][0] == '.');
			dp[0][i] = (a[0][i] == '.');
			m = max({m, dp[i][0], dp[0][i]});
		}
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < n; j++) {
				if(a[i][j] == '#') dp[i][j] = 0;
				else m = max(m, dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1);
			}
		} cout << m << '\n';
		for(int i = 0; i < n; i++) delete[] dp[i];
		delete[] dp;
		delete[] a;
	}
}