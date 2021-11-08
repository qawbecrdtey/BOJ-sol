#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool check(string const &s, string t) {
	if(s.size() == t.size()) return s == t;
	if(t.back() == 'A' && check(s, t.substr(0, t.size() - 1))) return true;
	if(t.front() == 'B') {
		reverse(t.begin(), t.end());
		t.pop_back();
		return check(s, t);
	}
	return false;
}
int main() {
	string s, t;
	cin >> s >> t;
	cout << check(s, t);
}