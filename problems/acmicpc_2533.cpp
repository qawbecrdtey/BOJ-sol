#include <iostream>
#include <utility>
#include <vector>
using namespace std;
pair<int, int> dfs(vector<int> const *v, int now, int prev) {
	int off = 0, on = 1;
	for(auto next : v[now]) {
		if(prev == next) continue;
		auto const p = dfs(v, next, now);
		off += p.second;
		on += min(p.first, p.second);
	}
	return { off, on };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto v = new vector<int>[n + 1];
	for(int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	auto const p = dfs(v, 1, -1);
	cout << min(p.first, p.second);
	delete[] v;
}