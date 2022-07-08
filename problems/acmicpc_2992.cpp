#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline bool check(string const &s, pair<char, int> const *a) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] < a[i].first) return true;
		if(s[i] > a[i].first) return false;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; auto a = new pair<char, int>[s.size()];
	for(int i = 0; i < s.size(); i++) {
		a[i] = { s[i], i };
	}
	while(next_permutation(a, a + s.size())) {
		if(check(s, a)) {
			for(int i = 0; i < s.size(); i++) {
				cout << a[i].first;
			} return 0;
		}
	} cout << 0;
}