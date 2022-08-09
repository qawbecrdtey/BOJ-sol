#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		cout << (s.size() == 7 && (s[0] == s[1] && s[1] == s[4]) && (s[2] == s[3] && s[3] == s[5] && s[5] == s[6]) && s[0] != s[2]) << '\n';
	}
}