#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; while(cin >> n >> m) {
		if(!n && !m) return 0;
		auto a = new string[n];
		auto visited = new bool*[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			visited[i] = new bool[m]();
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == '*' || visited[i][j]) continue;
				queue<pair<int, int>> q;
				q.push({ i, j });
				while(!q.empty()) {
					auto [nowx, nowy] = q.front(); q.pop();
					if(visited[nowx][nowy]) continue;
					visited[nowx][nowy] = true;
					if(nowx) {
						if(nowy && !visited[nowx - 1][nowy - 1] && a[nowx - 1][nowy - 1] == '@') q.push({ nowx - 1, nowy - 1 });
						if(!visited[nowx - 1][nowy] && a[nowx - 1][nowy] == '@') q.push({ nowx - 1, nowy });
						if(nowy < m - 1 && !visited[nowx - 1][nowy + 1] && a[nowx - 1][nowy + 1] == '@') q.push({ nowx - 1, nowy + 1 });
					}
					if(nowy && !visited[nowx][nowy - 1] && a[nowx][nowy - 1] == '@') q.push({ nowx, nowy - 1 });
					if(nowy < m - 1 && !visited[nowx][nowy + 1] && a[nowx][nowy + 1] == '@') q.push({ nowx, nowy + 1 });
					if(nowx < n - 1) {
						if(nowy && !visited[nowx + 1][nowy - 1] && a[nowx + 1][nowy - 1] == '@') q.push({ nowx + 1, nowy - 1 });
						if(!visited[nowx + 1][nowy] && a[nowx + 1][nowy] == '@') q.push({ nowx + 1, nowy });
						if(nowy < m - 1 && !visited[nowx + 1][nowy + 1] && a[nowx + 1][nowy + 1] == '@') q.push({ nowx + 1, nowy + 1 });
					}
				} cnt++;
			}
		}
		cout << cnt << '\n';
		for(int i = 0; i < n; i++) delete[] visited[i];
		delete[] visited;
		delete[] a;
	}
}