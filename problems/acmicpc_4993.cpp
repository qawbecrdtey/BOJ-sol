#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while(true) {
		int m, n;
		cin >> m >> n;
		if(!m && !n) return 0;
		auto a = new string[n];
		pair<int, int> start;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '@') start = {i, j};
			}
		}
		queue<pair<int, int>> q;
		q.push(start);
		auto visited = new bool *[n];
		for (int i = 0; i < n; i++) visited[i] = new bool[m]();
		int cnt = 0;
		while (!q.empty()) {
			auto [nowx, nowy] = q.front();
			q.pop();
			if (visited[nowx][nowy]) continue;
			visited[nowx][nowy] = true;
			cnt++;
			if (nowx && !visited[nowx - 1][nowy] && a[nowx - 1][nowy] != '#') q.push({nowx - 1, nowy});
			if (nowy && !visited[nowx][nowy - 1] && a[nowx][nowy - 1] != '#') q.push({nowx, nowy - 1});
			if (nowx < n - 1 && !visited[nowx + 1][nowy] && a[nowx + 1][nowy] != '#') q.push({nowx + 1, nowy});
			if (nowy < m - 1 && !visited[nowx][nowy + 1] && a[nowx][nowy + 1] != '#') q.push({nowx, nowy + 1});
		} cout << cnt << '\n';
		for(int i = 0; i < n; i++) delete[] visited[i];
		delete[] a; delete[] visited;
	}
}