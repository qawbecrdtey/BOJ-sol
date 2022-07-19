#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto v = new vector<int>[n + 1];
	while(m--) {
		int a, b; cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	auto visited = new int[n + 1];
	fill(visited, visited + n + 1, -1);
	queue<pair<int, int>> q;
	q.push({ r, 0 });
	while(!q.empty()) {
		auto [now, dist] = q.front(); q.pop();
		if(visited[now] != -1) continue;
		visited[now] = dist;
		for(auto next : v[now]) {
			if(visited[next] == -1) {
				q.push({ next, dist + 1 });
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}
}