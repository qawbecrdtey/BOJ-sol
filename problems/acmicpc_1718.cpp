#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s, t; getline(cin, s); getline(cin, t);
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') {
			cout << ' ';
			continue;
		}
		int x = s[i] - 'a';
		x -= t[i % t.size()] - 'a' + 1;
		while(x < 0) x += 26;
		x += 'a';
		cout << (char)(x);
	}
}