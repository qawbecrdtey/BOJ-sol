#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[4]; for(auto &i : a) cin >> i;
	vector<int> v[4];
	for(int i = 0; i < 4; i++) {
		v[i].reserve(a[i]);
		for(int j = 0; j < a[i]; j++) {
			int x; cin >> x; v[i].push_back(x);
		}
	}
	struct info { int sum, x, y; operator int() { return sum; }};
	vector<info> vv[2];
	for(int i = 0; i < a[0]; i++) {
		for(int j = 0; j < a[1]; j++) {
			vv[0].push_back({ v[0][i] + v[1][j], v[0][i], v[1][j] });
		}
	}
	for(int i = 0; i < a[2]; i++) {
		for(int j = 0; j < a[3]; j++) {
			vv[1].push_back({ -v[2][i] - v[3][j], v[2][i], v[3][j] });
		}
	}
	sort(vv[0].begin(), vv[0].end(), [](info const &a, info const &b) { return a.sum < b.sum; });
	for(auto [now, nowx, nowy] : vv[1]) {
		auto it = lower_bound(vv[0].begin(), vv[0].end(), now);
		if(it != vv[0].end() && it->sum == now) {
			cout << it->x << ' ' << it->y << ' ' << nowx << ' ' << nowy;
			return 0;
		}
	}
}