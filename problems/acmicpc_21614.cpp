#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	bool prev_right = false;
	string s; while(cin >> s) {
		if(s == "99999") return 0;
		if((s[0] + s[1]) & 1) { cout << "left "; prev_right = false; }
		else if(s[0] + s[1] != '0' + '0') { cout << "right "; prev_right = true; }
		else if(prev_right) cout << "right ";
		else cout << "left ";
		cout << s.substr(2) << '\n';
	}
}