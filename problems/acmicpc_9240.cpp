#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;
inline int ccw(pair<int, int> const &a, pair<int, int> const &b, pair<int, int> const &c) {
	int const x = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
	if(x > 0) return 1;
	if(!x) return 0;
	return -1;
}
inline int dist2(pair<int, int> const &a, pair<int, int> const &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
inline int dist2(pair<int, int> const &a) { return a.first * a.first + a.second * a.second; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	swap(*min_element(a, a + n), a[0]);
	auto const pivot = std::move(a[0]);
	a[0] = {};
	for(int i = 1; i < n; i++) a[i].first -= pivot.first, a[i].second -= pivot.second;
	sort(a + 1, a + n, [](pair<int, int> const &a, pair<int, int> const &b) {
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
	int max_dist = dist2(a[hull[other_side]]);
	auto visited = new bool[hull.size()]();
	do {
		visited[this_side] = true;
		swap(this_side, other_side);
		other_side = (int)(other_side + 1) % (int)(hull.size());
		while(dist2(a[hull[this_side]], a[hull[other_side]]) < dist2(a[hull[this_side]], a[hull[(other_side + 1) % hull.size()]])) {
			other_side = (other_side + 1) % (int)(hull.size());
		}
		int const x = dist2(a[hull[this_side]], a[hull[other_side]]);
		if(max_dist < x) max_dist = x;
	} while(!visited[other_side]);
	cout.precision(12);
	cout << fixed << sqrtl(max_dist);
	delete[] visited;
	delete[] a;
}