#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t; cin >> s >> t;
	bool flag = false;
	for(char c : s) if(c < '0' || c > '9') { flag = true; break; }
	for(char c : t) if(c < '0' || c > '9') { flag = true; break; }
	if(flag) cout << "NaN";
	else cout << stoi(s) - stoi(t);
}