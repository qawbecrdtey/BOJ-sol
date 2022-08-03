#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, d; cin >> n >> d;
	auto v = new vector<pair<int, int>>[d + 1];
	for(int i = 0; i < d; i++) {
		v[i].emplace_back( -1, i + 1 );
	}
	for(int i = 0; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		if(y > d) continue;
		v[x].emplace_back( -z, y );
	}
	auto visited = new bool[d + 1]();
	priority_queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while(!q.empty()) {
		auto [dist, now] = q.top(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		if(now == d) {
			cout << -dist;
			return 0;
		}
		for(auto [nextd, next] : v[now]) {
			if(!visited[next]) q.push({ nextd + dist, next });
		}
	}
}