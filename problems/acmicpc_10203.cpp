#include <iostream>
#include <string>
using namespace std;
inline bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		cout << "The number of vowels in ";
		string s; cin >> s;
		cout << s << " is ";
		int res = 0;
		for(char c : s) {
			res += is_vowel(c);
		} cout << res << ".\n";
	}
}