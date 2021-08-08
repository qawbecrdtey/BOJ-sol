#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	if(s[0] != t[0]) {
		cout << 0;
		return 0;
	}
	auto x = 1 % s.size(), y = 1 % t.size();
	while(x || y) {
		if(s[x] != t[y]) {
			cout << 0;
			return 0;
		}
		x = (x + 1) % s.size(); y = (y + 1) % t.size();
	}
	cout << 1;
}