#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto a = new string[n];
		auto visited = new bool*[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			visited[i] = new bool[m]();
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == '#' && !visited[i][j]) {
					cnt++;
					queue<pair<int, int>> q;
					q.push({i, j});
					while(!q.empty()) {
						auto [nowx, nowy] = q.front(); q.pop();
						if(visited[nowx][nowy]) continue;
						visited[nowx][nowy] = true;
						if(nowx && a[nowx - 1][nowy] == '#' && !visited[nowx - 1][nowy]) q.push({nowx - 1, nowy});
						if(nowy && a[nowx][nowy - 1] == '#' && !visited[nowx][nowy - 1]) q.push({ nowx, nowy - 1});
						if(nowx < n - 1 && a[nowx + 1][nowy] == '#' && !visited[nowx + 1][nowy]) q.push({nowx + 1, nowy});
						if(nowy < m - 1 && a[nowx][nowy + 1] == '#' && !visited[nowx][nowy + 1]) q.push({nowx, nowy + 1});
					}
				}
			}
		} cout << cnt << '\n';
		for(int i = 0; i < n; i++) delete[] visited[i];
		delete[] visited;
		delete[] a;
	}
}