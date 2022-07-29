#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	vector<int> v;
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) != m) continue;
		v.push_back(i);
	}
	int res = 0;
	for(auto i : v) {
		for(auto j : v) {
			res += (__builtin_popcount(i & j) >= k);
		}
	} cout << fixed; cout.precision(12);
	cout << res / static_cast<long double>(v.size() * v.size());
}