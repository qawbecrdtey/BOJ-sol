#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < s.size(); i++) {
		cout << (char)('0' + (s[i] == '1' && t[i] == '1'));
	} cout << '\n';
	for(int i = 0; i < s.size(); i++) {
		cout << (char)('0' + (s[i] == '1' || t[i] == '1'));
	} cout << '\n';
	for(int i = 0; i < s.size(); i++) {
		cout << (char)('0' + (s[i] != t[i]));
	} cout << '\n';
	for(char i : s) {
		cout << (char)('0' + ('1' - i));
	} cout << '\n';
	for(char i : t) {
		cout << (char)('0' + ('1' - i));
	} cout << '\n';
}