#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> const *v, vector<bool> &visited, vector<int> &adj, int now) {
	for(int next : v[now]) {
		if(visited[next]) continue;
		visited[next] = true;
		if(!adj[next] || dfs(v, visited, adj, adj[next])) {
			adj[next] = now;
			return true;
		}
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto v = new vector<int>[m + 1];
		for(int i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			v[i].reserve(y - x + 1);
			for(int j = x; j <= y; j++) v[i].emplace_back(j);
		}
		vector<bool> visited(n + 1);
		vector<int> adj(n + 1);
		int cnt = 0;
		for(int i = 1; i <= m; i++) {
			fill(visited.begin(), visited.end(), false);
			cnt += dfs(v, visited, adj, i);
		} cout << cnt << '\n';
		delete[] v;
	}
}