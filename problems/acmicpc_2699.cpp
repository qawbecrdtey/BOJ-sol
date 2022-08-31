#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline ll ccw(pair<ll, ll> const &a, pair<ll, ll> const &b, pair<ll, ll> const &c) {
	ll const x = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
	if(x > 0) return 1;
	if(!x) return 0;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new pair<ll, ll>[n];
		int mini = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			if(a[mini] > a[i]) mini = i;
		} swap(a[mini], a[0]);
		for(int i = 1; i < n; i++) {
			a[i].first -= a[0].first;
			a[i].second -= a[0].second;
		}
		auto pivot = std::move(a[0]);
		a[0] = {};
		sort(a + 1, a + n, [](pair<ll, ll> const &a, pair<ll, ll> const &b) {
			return a.second * b.first < b.second * a.first || (a.second * b.first == b.second * a.first && (a.first < b.first || (a.first == b.first && a.second < b.second)));
		});
		vector<int> s;
		s.push_back(0); s.push_back(1);
		for(int i = 2; i < n; i++) {
			while(s.size() > 1) {
				int second = s.back(); s.pop_back();
				int first = s.back();
				if(ccw(a[first], a[second], a[i]) == 1) {
					s.push_back(second);
					break;
				}
			}
			s.push_back(i);
		}
		auto x = max_element(s.begin(), s.end(), [a](int x, int y) {
			return a[x].second < a[y].second || (a[x].second == a[y].second && a[x].first > a[y].first);
		}) - s.begin();
		cout << s.size() << '\n';
		for(decltype(x) i = 0; i < s.size(); i++) {
			auto const idx = (x + s.size() - i) % s.size();
			cout << a[s[idx]].first + pivot.first << ' ' << a[s[idx]].second + pivot.second << '\n';
		}
		delete[] a;
	}
}