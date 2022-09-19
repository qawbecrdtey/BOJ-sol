#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	auto visited = new bool*[n];
	pair<int, int> start, end;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		visited[i] = new bool[m]();
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '*') visited[i][j] = true;
			else if(a[i][j] == 'B') start = { i, j };
			else if(a[i][j] == 'C') end = { i, j };
		}
	}
	struct info { int x; int y; int cnt; };
	queue<info> q;
	q.push({ start.first, start.second, 0 });
	while(!q.empty()) {
		auto const [nowx, nowy, nowcnt] = q.front(); q.pop();
		if(visited[nowx][nowy]) continue;
		visited[nowx][nowy] = true;
		if(nowx == end.first && nowy == end.second) {
			cout << nowcnt;
			return 0;
		}
		if(nowx && !visited[nowx - 1][nowy]) q.push({ nowx - 1, nowy, nowcnt + 1 });
		if(nowy && !visited[nowx][nowy - 1]) q.push({ nowx, nowy - 1, nowcnt + 1 });
		if(nowx < n - 1 && !visited[nowx + 1][nowy]) q.push({ nowx + 1, nowy, nowcnt + 1 });
		if(nowy < m - 1 && !visited[nowx][nowy + 1]) q.push({ nowx, nowy + 1, nowcnt + 1 });
	}
}