#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info { int now, dist, cnt; bool operator<(info const &i) const { return cnt > i.cnt || (cnt == i.cnt && dist > i.dist); }};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new vector<pair<int, int>>[n];
	for(int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[x].emplace_back(y, z);
	}
	vector<pair<int, int>> visited(n); // dist, cnt
	fill(visited.begin(), visited.end(), make_pair(-1, -1));
	priority_queue<info> pq;
	pq.push({0, 0, 0 });
	while(!pq.empty()) {
		auto [now, now_dist, now_cnt] = pq.top(); pq.pop();
		if(visited[now].first != -1) continue;
		visited[now].first = now_dist, visited[now].second = now_cnt;
		if(now == 1) {
			cout << now_dist;
			return 0;
		}
		for(auto [next, next_dist] : v[now]) {
			if(visited[next].first != -1) continue;
			pq.push({ next, next_dist + now_dist, now_cnt + 1 });
		}
	}
}