#include <iostream>
#include <string>
using namespace std;
inline string convert(string const &s) {
	string t(s.rbegin(), s.rend());
	for(char &c : t) {
		c = (char)('0' + '1' - c);
	}
	return s + "0" + t;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s("0");
	while(s.size() <= 100000) s = convert(s);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		int n; cin >> n;
		cout << s[n - 1] << '\n';
	}
}