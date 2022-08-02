#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int s; cin >> s;
	auto visited = new bool[n + 1]();
	queue<int> q; q.push(s);
	int cnt = 0;
	while(!q.empty()) {
		auto x = q.front(); q.pop();
		if(visited[x]) continue;
		visited[x] = true; cnt++;
		if(x - a[x] > 0 && !visited[x - a[x]]) q.push(x - a[x]);
		if(x + a[x] <= n && !visited[x + a[x]]) q.push(x + a[x]);
	} cout << cnt;
}