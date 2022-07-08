#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> const *v, vector<bool> &matched, vector<int> &adj, int now) {
	for(int next : v[now]) {
		if(matched[next]) continue;
		matched[next] = true;
		if(!adj[next] || dfs(v, matched, adj, adj[next])) {
			adj[next] = now;
			return true;
		}
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new vector<int>[n + 1];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		v[i].reserve(k);
		while(k--) {
			int x; cin >> x;
			v[i].emplace_back(x);
		}
	}
	vector<bool> matched(m + 1);
	vector<int> adj(m + 1);
	int res = 0;
	for(int i = 1; i <= n; i++) {
		fill(matched.begin(), matched.end(), false);
		res += dfs(v, matched, adj, i);
	} cout << res;
}