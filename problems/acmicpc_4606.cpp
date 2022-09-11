#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(true) {
		getline(cin, s);
		if(s == "#") return 0;
		for(char c : s) {
			switch(c) {
				case ' ': cout << "%20"; break;
				case '!': cout << "%21"; break;
				case '$': cout << "%24"; break;
				case '%': cout << "%25"; break;
				case '(': cout << "%28"; break;
				case ')': cout << "%29"; break;
				case '*': cout << "%2a"; break;
				default: cout << c;
			}
		} cout << '\n';
	}
}