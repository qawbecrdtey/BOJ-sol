#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		if(s[s.size() - 1] == 'a') cout << s << "s\n";
		else if(s[s.size() - 1] == 'i' || s[s.size() - 1] == 'y') cout << s.substr(0, s.size() - 1) << "ios\n";
		else if(s[s.size() - 1] == 'l') cout << s << "es\n";
		else if(s[s.size() - 1] == 'n') cout << s.substr(0, s.size() - 1) << "anes\n";
		else if(s[s.size() - 1] == 'e' && s[s.size() - 2] == 'n') cout << s.substr(0, s.size() - 2) << "anes\n";
		else if(s[s.size() - 1] == 'o') cout << s << "s\n";
		else if(s[s.size() - 1] == 'r') cout << s << "es\n";
		else if(s[s.size() - 1] == 't') cout << s << "as\n";
		else if(s[s.size() - 1] == 'u') cout << s << "s\n";
		else if(s[s.size() - 1] == 'v') cout << s << "es\n";
		else if(s[s.size() - 1] == 'w') cout << s << "as\n";
		else cout << s << "us\n";
	}
}