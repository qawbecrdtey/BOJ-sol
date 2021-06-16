#include <iostream>
#include <string>
using namespace std;
int main() {
	string s[3];
	int a[3];
	cin >> s[0] >> s[1] >> s[2];
	for(int i = 0; i < 3; i++) {
		auto it = s[i].find('.');
		if(it == string::npos) {
			a[i] = stoi(s[i].substr(0, it)) * 100;
			continue;
		}
		a[i] = stoi(s[i].substr(0, it)) * 100 + stoi(s[i].substr(it + 1));
	}
	bool flag = false;
	for(int i = 0; a[1] * i <= a[0]; i++) {
		if((a[0] - a[1] * i) % a[2] == 0) {
			flag = true;
			cout << i << ' ' << (a[0] - a[1] * i) / a[2] << '\n';
		}
	}
	if(!flag) {
		cout << "none";
	}
}