#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
	auto visited = new bool[f + 1]();
	queue<pair<int, int>> q;
	q.push({s, 0});
	while(!q.empty()) {
		auto [now, cnt] = q.front(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		if(now == g) {
			cout << cnt;
			return 0;
		}
		if(now > d && !visited[now - d]) q.push({ now - d, cnt + 1 });
		if(now + u <= f && !visited[now + u]) q.push({ now + u, cnt + 1});
	} cout << "use the stairs";
}