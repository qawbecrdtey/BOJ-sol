#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string sum(string &a, string &b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res;
	int i = 0, c = 0;
	while(i < a.size() && i < b.size()) {
		int const x = (a[i] - '0') + (b[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	while(i < a.size()) {
		int const x = (a[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	while(i < b.size()) {
		int const x = (b[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	if(c) {
		res.push_back('1');
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	auto a = new string*[n + 1];
	for(int i = 0; i <= n; i++) {
		a[i] = new string[i + 1];
		a[i][0] = a[i][i] = "1";
		for(int j = 1; j < i; j++) {
			a[i][j] = sum(a[i - 1][j], a[i - 1][j - 1]);
		}
	}
	cout << a[n][m];
}