#include <iostream>
#include <string>
using namespace std;
string reduce(string u) {
	for(int i = 1; i < u.size(); i++) {
		u[i - 1] = (char)((u[i - 1] + u[i] - '0' * 2) % 10 + '0');
	} u.pop_back(); return u;
}
int main() {
	string s, t; cin >> s >> t;
	string u;
	for(int i = 0; i < s.size(); i++) {
		u.push_back(s[i]);
		u.push_back(t[i]);
	}
	while(u.size() > 2) u = reduce(u);
	cout << u;
}