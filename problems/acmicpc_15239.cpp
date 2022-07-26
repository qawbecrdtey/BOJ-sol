#include <iostream>
#include <string>
using namespace std;
inline bool is_upper(char c) { return c >= 'A' && c <= 'Z'; }
inline bool is_lower(char c) { return c >= 'a' && c <= 'z'; }
inline bool is_digit(char c) { return c >= '0' && c <= '9'; }
inline bool is_symbol(char c) {
	char const s[] = "+_)(*&^%$#@!./,;{}";
	for(char cc : s) {
		if(c == cc) return true;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; string s; cin >> n >> s;
		if(n < 12) {
			cout << "invalid\n";
			continue;
		}
		bool upper = false, lower = false, digit = false, symbol = false;
		for(char c : s) {
			upper = upper || is_upper(c);
			lower = lower || is_lower(c);
			digit = digit || is_digit(c);
			symbol = symbol || is_symbol(c);
		}
		if(upper && lower && digit && symbol) {
			cout << "valid\n";
		} else cout << "invalid\n";
	}
}