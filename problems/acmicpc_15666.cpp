#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool cmp(vector<int> const &a, vector<int> const &b) {
	return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
void dfs(int const *a, set<vector<int>, decltype(cmp)*> &s, int n, int m, vector<int> v) {
	if(m == v.size()) {
		vector<int> res; res.reserve(m);
		for(int i = 0; i < m; i++) res.push_back(a[v[i]]);
		s.insert(res);
		return;
	}
	for(int i = (v.empty() ? 0 : v.back()); i < n; i++) {
		v.push_back(i);
		dfs(a, s, n, m, v);
		v.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a, a + n);
	set<vector<int>, decltype(cmp)*> s(cmp);
	dfs(a, s, n, m, {});
	for(auto const &v : s) {
		for(auto now : v) {
			cout << now << ' ';
		} cout << '\n';
	}
}