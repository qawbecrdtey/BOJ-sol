#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto visited = new bool[k + 1]();
	queue<pair<int, int>> q;
	q.push({n, 0});
	while(!q.empty()) {
		auto const [now, cnt] = q.front(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		if(now == k) {
			cout << cnt;
			return 0;
		}
		if(!visited[now + 1]) q.push({ now + 1, cnt + 1 });
		if((now << 1) <= k && !visited[now << 1]) q.push({ now << 1, cnt + 1 });
	}
}