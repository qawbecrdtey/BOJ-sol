#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
inline bool contained(bool const contains[26], char c, string const &s) {
	return s.size() >= 4 && all_of(s.begin(), s.end(), [contains](char c) {
		return contains[c - 'a'];
	}) && any_of(s.begin(), s.end(), [c](char cc) {
		return cc == c;
	});
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; int n; cin >> s >> n;
	bool contains[26]{};
	for(char c : s) contains[c - 'a'] = true;
	while(n--) {
		string t;
		cin >> t;
		if(contained(contains, s[0], t)) cout << t << '\n';
	}
}