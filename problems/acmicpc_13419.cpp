#include <iostream>
#include <string>
using namespace std;
int main() {
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		if(s.size() & 1) {
			for(int i = 0; i < s.size(); i++) cout << s[(i << 1) % s.size()]; cout << '\n';
			for(int i = 0; i < s.size(); i++) cout << s[((i << 1) | 1) % s.size()]; cout << '\n';
		}
		else {
			for(int i = 0; i < s.size(); i += 2) cout << s[i]; cout << '\n';
			for(int i = 1; i < s.size(); i += 2) cout << s[i]; cout << '\n';
		}
	}
}