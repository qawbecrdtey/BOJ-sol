#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	map<int, int> visited;
	int res = -1, cnt = 0;
	while(!q.empty()) {
		auto [now, now_cnt] = q.front(); q.pop();
		if(auto it = visited.find(now); it != visited.end() && it->second < now_cnt) continue;
		visited[now] = now_cnt;
		if(now == k) {
			if(res != -1 && now_cnt > res) break;
			res = now_cnt;
			cnt++;
			continue;
		}
		if(res == -1 && now <= k * 2 && visited.find(now + 1) == visited.end()) q.push({ now + 1, now_cnt + 1 });
		if(res == -1 && now >= 0 && visited.find(now - 1) == visited.end()) q.push({ now - 1, now_cnt + 1 });
		if(res == -1 && now <= k * 2 && visited.find(now * 2) == visited.end()) q.push({ now * 2, now_cnt + 1});
	} cout << res << '\n' << cnt;
}