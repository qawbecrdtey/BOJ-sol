#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(cin >> s) {
		if(s == "#") return 0;
		bool even = true;
		for(char c : s) if(c == '1') even = !even;
		if((s.back() == 'e') ^ even) {
			s.back() = '1';
		} else s.back() = '0';
		cout << s << '\n';
	}
}