#include <iostream>
#include <string>
using namespace std;
inline bool lucky(string const &s) {
	int l = 0, r = 0;
	for(int i = 0; i < s.size() / 2; i++) {
		l += s[i], r += s[s.size() / 2 + i];
	}
	return l == r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int l = (int)(s.size() & 0xFFFFFFFE);
	while(l) {
		for(int i = 0; i <= s.size() - l; i++) {
			if(lucky(s.substr(i, l))) {
				cout << l; return 0;
			}
		}
		l -= 2;
	} cout << 0;
}