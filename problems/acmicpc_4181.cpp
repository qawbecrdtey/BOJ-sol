#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline int ccw(pair<ll, ll> const &a, pair<ll, ll> const &b, pair<ll, ll> const &c) {
	ll const x = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
	if(x > 0) return 1;
	if(!x) return 0;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pair<ll, ll>> v;
	for(int i = 0; i < n; i++) {
		int x, y; char c[2];
		cin >> x >> y >> c;
		if(*c == 'Y') v.emplace_back(x, y);
	}
	swap(*min_element(v.begin(), v.end()), v[0]);
	auto pivot = v[0];
	for(auto &now : v) {
		now.first -= pivot.first;
		now.second -= pivot.second;
	}
	sort(v.begin() + 1, v.end(), [](pair<ll, ll> const &a, pair<ll, ll> const &b) {
		return a.second * b.first < b.second * a.first || (a.second * b.first == b.second * a.first && (a.first < b.first || (a.first == b.first && a.second < b.second)));
	});
	int i = (int)v.size() - 1;
	while(true) {
		if(v[i - 1].second * v.back().first != v[i - 1].first * v.back().second) break;
		i--;
	} reverse(v.begin() + i, v.end());
	cout << v.size() << '\n';
	for(auto [f, s] : v) {
		cout << f + pivot.first << ' ' << s + pivot.second << '\n';
	}
}