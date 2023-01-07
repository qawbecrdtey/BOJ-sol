#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	bool c = false, d = false;
	long long res = 1;
	for(char ch : s) {
		switch(ch) {
			case 'c': res *= 26 - c; c = true; d = false; break;
			case 'd': res *= 10 - d; c = false; d = true; break;
			default: __builtin_unreachable();
		}
	} cout << res;
}