#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
void dfs(set<int> *v, int *d, int now, int depth) {
	d[now] = depth;
	for(auto next : v[now]) {
		if(d[next] == -1) dfs(v, d, next, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto v = new set<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	auto d = new int[n + 1];
	fill(d, d + n + 1, -1);
	dfs(v, d, r, 0);
	for(int i = 1; i <= n; i++) {
		cout << d[i] << '\n';
	}
}