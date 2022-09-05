#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	set<vector<int>> s;
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) != m) continue;
		vector<int> v; v.reserve(m);
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) v.push_back(a[j]);
		}
		s.insert(std::move(v));
	}
	for(auto const &v : s) {
		for(int i : v) {
			cout << i << ' ';
		} cout << '\n';
	}
}