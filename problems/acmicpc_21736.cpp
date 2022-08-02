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
	pair<int, int> start;
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[m]();
		cin >> a[i];
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'I') {
				start = { i, j };
			}
			else if(a[i][j] == 'X') {
				visited[i][j] = true;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push(std::move(start));
	int cnt = 0;
	while(!q.empty()) {
		auto [nowx, nowy] = q.front(); q.pop();
		if(visited[nowx][nowy]) continue;
		visited[nowx][nowy] = true;
		cnt += (a[nowx][nowy] == 'P');
		if(nowx && !visited[nowx - 1][nowy]) q.push({ nowx - 1, nowy });
		if(nowy && !visited[nowx][nowy - 1]) q.push({ nowx, nowy - 1 });
		if(nowx < n - 1 && !visited[nowx + 1][nowy]) q.push({ nowx + 1, nowy });
		if(nowy < m - 1 && !visited[nowx][nowy + 1]) q.push({ nowx, nowy + 1 });
	}
	if(!cnt) {
		cout << "TT";
	} else cout << cnt;
}