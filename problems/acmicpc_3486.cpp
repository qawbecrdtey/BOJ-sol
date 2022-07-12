#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline void clear(string &s) {
	while(!s.empty() && s.back() == '0') s.pop_back();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s[2]; cin >> s[0] >> s[1];
		reverse(s[0].begin(), s[0].end());
		reverse(s[1].begin(), s[1].end());
		clear(s[0]); clear(s[1]);
		int n = stoi(s[0]) + stoi(s[1]);
		while(!(n % 10)) n /= 10;
		while(n) {
			cout << n % 10;
			n /= 10;
		} cout << '\n';
	}
}