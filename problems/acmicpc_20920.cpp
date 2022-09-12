#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	map<string, int> mp;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		if(s.size() < m) continue;
		mp[s]++;
	}
	vector<pair<int, string>> v;
	for(auto &now : mp) {
		v.emplace_back(now.second, now.first);
	}
	sort(v.begin(), v.end(), [](pair<int, string> const &a, pair<int, string> const &b) {
		return a.first > b.first || (a.first == b.first && (a.second.length() > b.second.length() || (a.second.length() == b.second.length() && a.second < b.second)));
	});
	for(auto const &now : v) cout << now.second << '\n';
}