#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline char is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
inline bool contains_vowel(string const &t) {
	return any_of(t.begin(), t.end(), [](char c) {
		return is_vowel(c);
	});
}
inline bool consecutive(string const &t) {
	for(int i = 0; i < (int)(t.size()) - 2; i++) {
		if(is_vowel(t[i]) && is_vowel(t[i + 1]) && is_vowel(t[i + 2])) return true;
		if(!is_vowel(t[i]) && !is_vowel(t[i + 1]) && !is_vowel(t[i + 2])) return true;
	} return false;
}
inline bool same_consecutive(string const &t) {
	for(int i = 0; i < (int)(t.size()) - 1; i++) {
		if(t[i] == t[i + 1] && t[i] != 'e' && t[i] != 'o') return true;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string t; while(cin >> t) {
		if(t == "end") return 0;
		cout << '<' << t << "> is";
		if(!contains_vowel(t) || consecutive(t) || same_consecutive(t)) cout << " not";
		cout << " acceptable.\n";
	}
}