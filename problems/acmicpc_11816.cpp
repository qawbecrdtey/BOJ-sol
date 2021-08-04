#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	if(s[0] != '0') {
		cout << s;
		return 0;
	}
	int n = 0;
	if(s[1] != 'x') {
		for(int i = 1; i < s.size(); i++) {
			n *= 8;
			n += s[i] - '0';
		}
		cout << n;
		return 0;
	}
	for(int i = 2; i < s.size(); i++) {
		n *= 16;
		if(s[i] >= '0' && s[i] <= '9') n += s[i] - '0';
		else n += 10 + s[i] - 'a';
	}
	cout << n;
}