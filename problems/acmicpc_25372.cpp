#include <iostream>
#include <string>
using namespace std;
int main() {
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		if(s.size() > 5 && s.size() < 10) cout << "yes\n";
		else cout << "no\n";
	}
}