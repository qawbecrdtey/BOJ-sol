#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; int res = 1;
	for(char c : s) {
		switch(c) {
			case 'A': if(res != 3) res = 3 - res; break;
			case 'B': if(res != 1) res = 5 - res; break;
			case 'C': if(res != 2) res = 4 - res; break;
			default: __builtin_unreachable();
		}
	} cout << res;
}