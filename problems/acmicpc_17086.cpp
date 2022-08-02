#include <iostream>
#include <vector>
using namespace std;
inline int dist(pair<int, int> const &a, pair<int, int> const &b) {
	return max(abs(a.first - b.first), abs(a.second - b.second));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x; cin >> x;
			if(x) v.emplace_back(i, j);
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x = n + m + 1;
			for(auto now : v) {
				int const y = dist({ i, j }, now);
				if(y < x) x = y;
			} if(res < x) res = x;
		}
	} cout << res;
}