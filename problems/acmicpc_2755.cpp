#include <iostream>
#include <string>
using namespace std;
inline int convert(string const &s) {
	if(s[0] == 'F') return 0;
	int res;
	switch(s[0]) {
		case 'A': res = 40; break;
		case 'B': res = 30; break;
		case 'C': res = 20; break;
		case 'D': res = 10; break;
		default: __builtin_unreachable();
	}
	switch(s[1]) {
		case '+': res += 3;
		case '0': break;
		case '-': res -= 3; break;
		default: __builtin_unreachable();
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int sum = 0, cnt = 0;
	while(n--) {
		string s, t; int x; cin >> s >> x >> t;
		sum += x * convert(t); cnt += x;
	}
	cout.precision(2);
	cout << fixed << (long double)(sum) / (cnt * 10);
}