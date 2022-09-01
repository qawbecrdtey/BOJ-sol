#include <algorithm>
#include <cmath>
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
inline long double dist(pair<ll, ll> const &a, pair<ll, ll> const &b) {
	return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, l; cin >> n >> l;
	auto a = new pair<ll, ll>[n];
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	swap(*min_element(a, a + n), a[0]);
	for(int i = 1; i < n; i++) a[i].first -= a[0].first, a[i].second -= a[0].second;
	a[0] = {};
	sort(a + 1, a + n, [](pair<ll, ll> const &a, pair<ll, ll> const &b) {
		return a.second * b.first < a.first * b.second || (a.second * b.first == a.first * b.second && (a.first < b.first || (a.first == b.first && a.second < b.second)));
	});
	vector<int> hull{ 0, 1 };
	for(int i = 2; i < n; i++) {
		while(hull.size() > 1) {
			int second = hull.back(); hull.pop_back();
			int first = hull.back();
			if(ccw(a[first], a[second], a[i]) == 1) {
				hull.push_back(second);
				break;
			}
		} hull.push_back(i);
	}
	long double d = 2 * l * M_PIl;
	for(int i = 0; i < hull.size(); i++) {
		d += dist(a[hull[i]], a[hull[(i + 1) % hull.size()]]);
	} cout.precision(0);
	cout << fixed << d;
}