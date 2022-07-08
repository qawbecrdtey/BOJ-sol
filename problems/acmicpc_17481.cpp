#include <algorithm>
#include <iostream>
#include <map>
#include <string>
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
	map<string, int> mp;
	auto v = new vector<int>[n + 1];
	for(int i = 1; i <= m; i++) {
		string s; cin >> s;
		mp[s] = i;
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		v[i].reserve(k);
		for(int j = 0; j < k; j++) {
			string s; cin >> s;
			v[i].emplace_back(mp[s]);
		}
	}
	vector<bool> visited(m + 1);
	vector<int> adj(m + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		cnt += dfs(v, visited, adj, i);
	}
	if(cnt == n) cout << "YES";
	else cout << "NO\n" << cnt;
}