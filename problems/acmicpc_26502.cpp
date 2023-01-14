#include <iostream>
#include <string>
using namespace std;
inline char swapped(char c) {
	switch(c) {
		case 'A': return 'E';
		case 'E': return 'I';
		case 'I': return 'O';
		case 'O': return 'U';
		case 'U': return 'Y';
		case 'Y': return 'A';
		case 'a': return 'e';
		case 'e': return 'i';
		case 'i': return 'o';
		case 'o': return 'u';
		case 'u': return 'y';
		case 'y': return 'a';
		default: return c;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s); int t = stoi(s); while(t--) {
		getline(cin, s); for(char c : s) cout << swapped(c);
		cout << '\n';
	}
}