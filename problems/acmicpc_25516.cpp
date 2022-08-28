#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<int> const *v, int const *c, int now, int prev, int depth, int max_depth) {
	if(depth > max_depth) return 0;
	int res = c[now];
	for(auto next : v[now]) {
		if(next == prev) continue;
		res += dfs(v, c, next, now, depth + 1, max_depth);
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto v = new vector<int>[n];
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto c = new int[n];
	for(int i = 0; i < n; i++) cin >> c[i];
	cout << dfs(v, c, 0, -1, 0, k);
}