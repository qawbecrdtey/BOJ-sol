#include <iostream>
#include <string>
using namespace std;
inline bool check(string const &s) {
	for(int i = 1; i < s.size(); i++) {
		long long x = 1, y = 1;
		for(int j = 0; j < i; j++) x *= s[j] - '0';
		for(int j = i; j < s.size(); j++) y *= s[j] - '0';
		if(x == y) return true;
	} return false;
}
int main() {
	string s; cin >> s;
	if(check(s)) cout << "YES";
	else cout << "NO";
}