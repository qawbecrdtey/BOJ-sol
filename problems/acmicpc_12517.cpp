#include <iostream>
#include <string>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;
		cout << s << " is ruled by ";
		if(s.back() == 'y') {
			cout << "nobody.\n";
			continue;
		}
		if(s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u') {
			cout << "a queen.\n";
			continue;
		}
		cout << "a king.\n";
	}
}