#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s, t; cin >> s;
	while(cin >> t) {
		for(char &c : s) {
			if(c == t[0]) c += 'a' - 'A';
		}
	} cout << s;
}