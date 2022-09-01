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
inline ll dist2(pair<ll, ll> const &a, pair<ll, ll> const &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
inline ll dist2(pair<ll, ll> const &a) { return a.first * a.first + a.second * a.second; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) {
		int n; cin >> n;
		auto a = new pair<ll, ll>[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		swap(*min_element(a, a + n), a[0]);
		auto pivot = a[0];
		a[0] = {};
		for(int i = 1; i < n; i++) a[i].first -= pivot.first, a[i].second -= pivot.second;
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
			}
			hull.push_back(i);
		}
		int this_side = 0, other_side = (int)(max_element(hull.begin() + 1, hull.end(), [a](int x, int y) {
			return dist2(a[x]) < dist2(a[y]);
		}) - hull.begin());
		auto visited = new bool[hull.size()]();
		ll max_dist = dist2(a[hull[other_side]]);
		pair<int, int> max_pair{ this_side, other_side };
		do {
			visited[this_side] = true;
			int this_next = (this_side + 1) % (int)(hull.size());
			int other_next = (other_side + 1) % (int)(hull.size());
			if(ccw({ a[hull[this_side]].first - a[hull[this_next]].first, a[hull[this_side]].second - a[hull[this_next]].second }, { 0, 0 }, { a[hull[other_next]].first - a[hull[other_side]].first, a[hull[other_next]].second - a[hull[other_side]].second }) == 1) {
				other_side = other_next;
			}
			else this_side = this_next;
			ll const x = dist2(a[hull[this_side]], a[hull[other_side]]);
			if(max_dist < x) {
				max_dist = x;
				max_pair = { this_side, other_side };
			}
		} while(!visited[this_side] || !visited[other_side]);
		cout << a[hull[max_pair.first]].first + pivot.first << ' ' << a[hull[max_pair.first]].second + pivot.second << ' ' << a[hull[max_pair.second]].first + pivot.first << ' ' << a[hull[max_pair.second]].second + pivot.second << '\n';
		delete[] visited;
		delete[] a;
	}
}