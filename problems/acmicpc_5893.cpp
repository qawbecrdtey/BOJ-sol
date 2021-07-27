#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string add(string const &a, string const &b) {
	int i = 0;
	int c = 0;
	string res;
	while(i < a.size() && i < b.size()) {
		int x = (a[i] - '0') + (b[i] - '0') + c;
		res.push_back(x % 2 + '0');
		c = x / 2;
		i++;
	}
	while(i < a.size()) {
		int x = (a[i] - '0') + c;
		res.push_back(x % 2 + '0');
		c = x / 2;
		i++;
	}
	while(i < b.size()) {
		int x = (b[i] - '0') + c;
		res.push_back(x % 2 + '0');
		c = x / 2;
		i++;
	}
	if(c) {
		res.push_back('1');
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	string s, t;
	cin >> s;
	t = s;
	for(int i = 0; i < 4; i++) t.push_back('0');
	reverse(t.begin(), t.end());
	reverse(s.begin(), s.end());
	cout << add(t, s);
}