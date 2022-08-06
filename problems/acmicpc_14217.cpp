#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new set<int>[n +  1];
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	auto dist = new int[n + 1];
	int t; cin >> t; while(t--) {
		int a, x, y; cin >> a >> x >> y;
		if(a == 1) {
			v[x].insert(y);
			v[y].insert(x);
		}
		else {
			v[x].erase(y);
			v[y].erase(x);
		}
		queue<pair<int, int>> q;
		q.push({ 1, 0 });
		fill(dist, dist + n + 1, -1);
		while(!q.empty()) {
			auto [now, d] = q.front(); q.pop();
			if(dist[now] != -1) continue;
			dist[now] = d;
			for(int next : v[now]) {
				if(dist[next] == -1) {
					q.push({ next, d + 1 });
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			cout << dist[i] << ' ';
		} cout << '\n';
	}
}