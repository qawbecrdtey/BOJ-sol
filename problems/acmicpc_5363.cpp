#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s); int t = stoi(s); while(t--) {
		getline(cin, s);
		int cnt = 2, i = 0;
		for(; i < s.size() && cnt; i++) {
			cnt -= (s[i] == ' ');
		} cout << s.substr(i) << ' ' << s.substr(0, i - 1) << '\n';
	}
}