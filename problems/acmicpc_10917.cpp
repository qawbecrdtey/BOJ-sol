#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto v = new vector<int>[n + 1];
	while(m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	auto visited = new bool[n + 1]();
	while(!q.empty()) {
		auto const now = q.front(); q.pop();
		if(visited[now.first]) continue;
		visited[now.first] = true;
		if(now.first == n) {
			printf("%d", now.second);
			return 0;
		}
		for(auto next : v[now.first]) {
			if(!visited[next]) q.push({ next, now.second + 1 });
		}
	}
	printf("-1");
}