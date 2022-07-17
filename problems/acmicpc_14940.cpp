#include <iostream>
#include <queue>
using namespace std;
struct info { int x, y; int cnt; };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int*[n];
	auto b = new int*[n];
	auto visited = new bool*[n];
	pair<int, int> start;
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		b[i] = new int[m]();
		visited[i] = new bool[m]();
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(!a[i][j]) visited[i][j] = true;
			else if(a[i][j] == 2) start = {i, j};
			else b[i][j] = -1;
		}
	}
	queue<info> q;
	q.push({ start.first, start.second, 0 });
	while(!q.empty()) {
		auto [nowx, nowy, cnt] = q.front(); q.pop();
		if(visited[nowx][nowy]) continue;
		visited[nowx][nowy] = true;
		b[nowx][nowy] = cnt;
		if(nowx && !visited[nowx - 1][nowy]) q.push({ nowx - 1, nowy, cnt + 1 });
		if(nowy && !visited[nowx][nowy - 1]) q.push({ nowx, nowy - 1, cnt + 1 });
		if(nowx < n - 1 && !visited[nowx + 1][nowy]) q.push({ nowx + 1, nowy, cnt + 1 });
		if(nowy < m - 1 && !visited[nowx][nowy + 1]) q.push({ nowx, nowy + 1, cnt + 1 });
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << b[i][j] << ' ';
		} cout << '\n';
	}
}