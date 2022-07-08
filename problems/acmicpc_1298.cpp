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
	int n, m; cin >> n >> m;
	auto v = new vector<int>[n + 1];
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	vector<bool> visited(n + 1);
	vector<int> adj(n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		cnt += dfs(v, visited, adj, i);
	} cout << cnt;
}