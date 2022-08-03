#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto s = new set<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
	auto visited = new bool[n + 1]();
	queue<pair<int, int>> q;
	q.push({r, 0});
	long long res = 0;
	long long cnt = 0;
	while(!q.empty()) {
		auto [now, nowd] = q.front(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		res += nowd * (++cnt);
		for(auto it = s[now].rbegin(); it != s[now].rend(); ++it) {
			if(!visited[*it]) {
				q.push({*it, nowd + 1});
			}
		}
	}
	cout << res;
}