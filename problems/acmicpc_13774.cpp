#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string const &s) {
	for(int i = 0; i < s.size() / 2; i++) {
		if(s[i] != s[s.size() - i - 1]) return false;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(cin >> s) {
		if(s == "#") return 0;
		for(int i = 0; i < s.size(); i++) {
			string t = s.substr(0, i) + s.substr(i + 1);
			if(is_palindrome(t)) {
				cout << t << '\n';
				goto END;
			}
		}
		cout << "not possible\n";
	END:continue;
	}
}