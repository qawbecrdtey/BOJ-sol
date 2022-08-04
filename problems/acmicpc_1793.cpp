#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res;
	int idx = 0;
	int c = 0;
	while(idx < a.size() && idx < b.size()) {
		int const x = a[idx] + b[idx] - 2 * '0' + c;
		res.push_back((char)(x % 10 + '0'));
		c = x / 10;
		idx++;
	}
	while(idx < a.size()) {
		int const x = a[idx] - '0' + c;
		res.push_back((char)(x % 10 + '0'));
		c = x / 10;
		idx++;
	}
	while(idx < b.size()) {
		int const x = b[idx] - '0' + c;
		res.push_back((char)(x % 10 + '0'));
		c = x / 10;
		idx++;
	}
	if(c) res.push_back('1');
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<int> v; int x;
	while(cin >> x) {
		v.push_back(x);
	}
	int m = *max_element(v.begin(), v.end());
	auto dp = new string[m + 1];
	dp[0] = "1", dp[1] = "1";
	for(int i = 2; i <= m; i++) {
		dp[i] = add(dp[i - 1], add(dp[i - 2], dp[i - 2]));
	}
	for(auto now : v) {
		cout << dp[now] << '\n';
	}
}