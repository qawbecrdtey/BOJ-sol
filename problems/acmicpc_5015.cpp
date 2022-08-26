#include <iostream>
#include <memory>
using namespace std;
bool match(unique_ptr<unique_ptr<unique_ptr<bool>[]>[]> &dp, string const &s, string const &t, size_t x, size_t y) {
	if(dp[x][y] != nullptr) return *dp[x][y];
	if(x == s.size() && y == t.size()) return *(dp[x][y] = make_unique<bool>(true));
	if(x == s.size()) return *(dp[x][y] = make_unique<bool>(false));
	if(y == t.size()) {
		if(s[x] == '*') return *(dp[x][y] = make_unique<bool>(match(dp, s, t, x + 1, y)));
		else return *(dp[x][y] = make_unique<bool>(false));
	}
	if(s[x] == '*') return *(dp[x][y] = make_unique<bool>(match(dp, s, t, x + 1, y) || match(dp, s, t, x, y + 1)));
	return *(dp[x][y] = make_unique<bool>(s[x] == t[y] && match(dp, s, t, x + 1, y + 1)));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; int n; cin >> s >> n;
	while(n--) {
		string t; cin >> t;
		auto dp = make_unique<unique_ptr<unique_ptr<bool>[]>[]>(s.size() + 1);
		for(int i = 0; i <= s.size(); i++) dp[i] = make_unique<unique_ptr<bool>[]>(t.size() + 1);
		if(match(dp, s, t, 0, 0)) cout << t << '\n';
	}
}