#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char*[n];
	auto visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[m]();
		a[i] = new char[m + 1];
		scanf("%s", a[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '.') continue;
			if(!visited[i][j]) {
				cnt++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				while(!q.empty()) {
					auto const now = q.front(); q.pop();
					if(visited[now.first][now.second]) continue;
					visited[now.first][now.second] = true;
					if(i && a[i - 1][j] != '.' && !visited[i - 1][j]) q.push({ i - 1, j });
					if(j && a[i][j - 1] != '.' && !visited[i][j - 1]) q.push({ i, j - 1 });
					if(i < n - 1 && a[i + 1][j] != '.' && !visited[i + 1][j]) q.push({ i + 1, j });
					if(j < m - 1 && a[i][j + 1] != '.' && !visited[i][j + 1]) q.push({ i, j + 1 });
				}
			}
		}
	}
	printf("%d", cnt);
}