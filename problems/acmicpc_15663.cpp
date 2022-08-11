#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool cmp(vector<int> const &a, vector<int> const &b) {
	for(int i = 0; i < a.size() && i < b.size(); i++) {
		if(a[i] < b[i]) return true;
		if(a[i] > b[i]) return false;
	} if(a.size() > b.size()) return true;
	return false;
}
void dfs(int const *a, int n, int m, vector<int> v, set<vector<int>, decltype(&cmp)> &s) {
	if(m == v.size()) {
		vector<int> res; res.reserve(m);
		for(int i = 0; i < m; i++) res.push_back(a[v[i]]);
		s.insert(std::move(res));
		return;
	}
	for(int i = 0; i < n; i++) {
		if(find(v.begin(), v.end(), i) != v.end()) continue;
		v.push_back(i);
		dfs(a, n, m, v, s);
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
	set<vector<int>, decltype(&cmp)> s(&cmp);
	dfs(a, n, m, {}, s);
	for(auto const &v : s) {
		for(auto now : v) {
			cout << now << ' ';
		} cout << '\n';
	}
}