#include <iostream>
#include <vector>
using namespace std;
inline int dist(pair<int, int> const &a, pair<int, int> const &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '1') v.emplace_back(i, j);
		}
	}
	int res = 123123123;
	for(int i = 0; i < n * m; i++) {
		for(int j = 0; j < n * m; j++) {
			if(i == j) continue;
			int const x1 = i / m;
			int const y1 = i % m;
			int const x2 = j / m;
			int const y2 = j % m;
			auto const p1 = make_pair(x1, y1);
			auto const p2 = make_pair(x2, y2);
			if(a[x1][y1] == '1' || a[x2][y2] == '1') continue;
			int d = 0;
			for(auto const p : v) {
				int const t = min(dist(p1, p), dist(p2, p));
				if(d < t) d = t;
			}
			if(res > d) res = d;
		}
	} cout << res;
}