#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
void dfs(set<int> *s, int *d, int now, int depth) {
	d[now] = depth;
	for(auto it = s[now].rbegin(); it != s[now].rend(); ++it) {
		if(d[*it] == -1) dfs(s, d, *it, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto s = new set<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
	auto d = new int[n + 1];
	fill(d, d + n + 1, -1);
	dfs(s, d, r, 0);
	for(int i = 1; i <= n; i++) {
		cout << d[i] << '\n';
	}
}