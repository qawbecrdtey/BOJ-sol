#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string sum(string &s, string &t) {
	string res;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int idx = 0, c = 0;
	while(idx < s.size() && idx < t.size()) {
		int const x = s[idx] - '0' + t[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	while(idx < s.size()) {
		int const x = s[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	while(idx < t.size()) {
		int const x = t[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	if(c) res.push_back('1');
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	cin >> n;
	auto a = new string[n + 2]();
	a[0] = "0";
	a[1] = "1";
	for(int i = 2; i <= n; i++) {
		a[i] = sum(a[i - 1], a[i - 2]);
	}
	cout << a[n];
}