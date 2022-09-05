#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline bool contains(string const &s, char c) {
	return any_of(s.begin(), s.end(), [c](char cc) { return cc == c; });
}
inline void convert(string &s, initializer_list<char> il, char c) {
	for(char &cc : s) {
		if(find(il.begin(), il.end(), cc) != il.end()) cc = c;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	if(contains(s, 'A')) convert(s, { 'B', 'C', 'D', 'F' }, 'A');
	else if(contains(s, 'B')) convert(s, { 'C', 'D', 'F' }, 'B');
	else if(contains(s, 'C')) convert(s, { 'D', 'F' }, 'C');
	else s = string(s.size(), 'A');
	cout << s;
}