#include <iostream>
#include <string>
using namespace std;
bool is_palindrome0(string const &s, int l, int r) {
	while(l < r) {
		if(s[l] != s[r]) return false;
		l++; r--;
	} return true;
}
bool is_palindrome1(string const &s, int l, int r) {
	while(l < r) {
		if(s[l] != s[r]) {
			return is_palindrome0(s, l + 1, r) || is_palindrome0(s, l, r - 1);
		} l++; r--;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		if(is_palindrome0(s, 0, s.size() - 1)) cout << "0\n";
		else if(is_palindrome1(s, 0, s.size() - 1)) cout << "1\n";
		else cout << "2\n";
	}
}