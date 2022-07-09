#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline int value(char c) {
	switch(c) {
		case '-': return 0;
		case '\\': return 1;
		case '(': return 2;
		case '@': return 3;
		case '?': return 4;
		case '>': return 5;
		case '&': return 6;
		case '%': return 7;
		case '/': return -1;
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(cin >> s) {
		if(s == "#") return 0;
		reverse(s.begin(), s.end());
		long long res = 0, mul = 1;
		for(char c : s) {
			res += value(c) * mul;
			mul *= 8;
		} cout << res << '\n';
	}
}