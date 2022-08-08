#include <iostream>
#include <set>
#include <string>
using namespace std;
constexpr __int128_t one = 1;
inline bool match(string const &s, size_t idx, string const &t) {
	if(idx + t.size() > s.size()) return false;
	for(size_t i = 0; i < t.size(); i++) {
		if(s[i + idx] != t[i]) return false;
	} return true;
}
bool dp(string const &main_str, set<__int128_t> &s, string const *a, __int128_t now, int n, size_t idx) {
	if(auto it = s.find(now); it != s.end()) return false;
	s.insert(now);
	if(idx == main_str.size()) return true;
	for(int i = 0; i < n; i++) {
		if(!(now & (one << i)) && match(main_str, idx, a[i]) && dp(main_str, s, a, now | (one << i), n, idx + a[i].size())) return true;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int n; cin >> n;
	auto a = new string[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	set<__int128_t> st;
	cout << dp(s, st, a, 0, n, 0);
}