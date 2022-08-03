#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new string[n];
	auto visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		visited[i] = new bool[n]();
	} int res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == '*' && !visited[i][j]) {
				res++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				while(!q.empty()) {
					auto [nowx, nowy] = q.front(); q.pop();
					if(visited[nowx][nowy]) continue;
					visited[nowx][nowy] = true;
					if(nowx && a[nowx - 1][nowy] == '*' && !visited[nowx - 1][nowy]) q.push({ nowx - 1, nowy });
					if(nowy && a[nowx][nowy - 1] == '*' && !visited[nowx][nowy - 1]) q.push({ nowx, nowy - 1 });
					if(nowx < n - 1 && a[nowx + 1][nowy] == '*' && !visited[nowx + 1][nowy]) q.push({ nowx + 1, nowy });
					if(nowy < n - 1 && a[nowx][nowy + 1] == '*' && !visited[nowx][nowy + 1]) q.push({ nowx, nowy + 1 });
				}
			}
		}
	} cout << res;
}
