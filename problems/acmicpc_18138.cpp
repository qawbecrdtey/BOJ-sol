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
	auto a = new int[n + 1];
	auto v = new vector<int>[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) {
		int x; cin >> x;
		for(int j = 1; j <= n; j++) {
			if(((a[j] + 1) / 2 <= x && a[j] * 3 / 4 >= x) || (a[j] <= x && a[j] * 5 / 4 >= x)) {
				v[j].push_back(i);
			}
		}
	}
	vector<bool> visited(m + 1);
	vector<int> adj(m + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		cnt += dfs(v, visited, adj, i);
	} cout << cnt;
}