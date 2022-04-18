#include <iostream>
#include <queue>
using namespace std;
vector<int> bfs(vector<int> const *v, int n) {
	vector<bool> visited(n + 1);
	vector<int> dist(n);
	fill(dist.begin(), dist.end(), -1);
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	while(!q.empty()) {
		auto const [now, nowdist] = q.front(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		dist[now - 1] = nowdist;
		for(auto next : v[now]) {
			if(!visited[next]) q.push({ next, nowdist + 1 });
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new vector<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		auto const res = bfs(v, n);
		for(auto const now : res) cout << now << ' '; cout << '\n';
	}
}