#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	map<string, int> m;
	string s; while(n--) {
		cin >> s;
		m[s] = 0;
	}
	while(cin >> s) m[s]++;
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<string, int> const &a, pair<string, int> const &b) {
		return a.second > b.second || (a.second == b.second && a.first < b.first);
	});
	for(auto const &[str, i] : v) {
		cout << str << ' ' << i << '\n';
	}
}