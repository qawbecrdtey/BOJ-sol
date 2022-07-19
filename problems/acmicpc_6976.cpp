#include <iostream>
#include <string>
using namespace std;
string subtract(string s, int b) {
	int c = 0;
	for(auto it = s.rbegin(); it != s.rend(); ++it) {
		*it -= b + c;
		if(*it < '0') *it += 10, c = 1;
		else c = 0;
		b = 0;
	}
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '0') {
			return s.substr(i);
		}
	} __builtin_unreachable();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s, ss; cin >> s; ss = s;
		cout << s << '\n';
		while(ss.size() > 2) {
			ss = subtract(ss.substr(0, ss.size() - 1), ss.back() - '0');
			cout << ss << '\n';
		}
		if((ss.size() == 1 && ss[0] != '0') || (ss.size() == 2 && ss[0] != ss[1])) {
			cout << "The number " << s << " is not divisible by 11.\n\n";
			continue;
		}
		if((ss.size() == 1 && ss[0] == '0') || (ss.size() == 2 && ss[0] == ss[1])) {
			cout << "The number " << s << " is divisible by 11.\n\n";
			continue;
		} __builtin_unreachable();
	}
}