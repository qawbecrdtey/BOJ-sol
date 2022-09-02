#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pair<int, int>> v{{0, 0}};
	for(int i = 0; i < 6; i++) {
		int x, y; cin >> x >> y;
		switch(x) {
			case 1: v.emplace_back(v.back().first + y, v.back().second); break;
			case 2: v.emplace_back(v.back().first - y, v.back().second); break;
			case 3: v.emplace_back(v.back().first, v.back().second + y); break;
			case 4: v.emplace_back(v.back().first, v.back().second - y); break;
			default: __builtin_unreachable();
		}
	} int res = 0;
	for(int i = 0; i < v.size() - 1; i++) {
		res += v[i].first * v[i + 1].second - v[i].second * v[i + 1].first;
	} cout << abs(res) / 2 * n;
}