#include <iostream>
#include <string>
using namespace std;
inline char f(char c) {
	if(c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
	return c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(getline(cin, s)) {
		bool flag = false;
		for(int i = 0; i < (int)s.size() - 6; i++) {
			if(f(s[i]) == 'p' && f(s[i + 1]) == 'r' && f(s[i + 2]) == 'o' && f(s[i + 3]) == 'b' && f(s[i + 4]) == 'l' && f(s[i + 5]) == 'e' && f(s[i + 6]) == 'm') {
				flag = true;
				break;
			}
		}
		if(flag) cout << "yes\n" << flush;
		else cout << "no\n" << flush;
	}
}