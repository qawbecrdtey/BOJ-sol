#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int*[n];
	auto visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		visited[i] = new bool[m];
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int time = -1;
	vector<pair<int, int>> check;

	do {
		struct info { int x, y, cheese; bool operator<(info const &i) const { return cheese > i.cheese; }};
		for(int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + m, false);
		}
		time++;
		for(auto [x, y] : check) {
			a[x][y] = 0;
		}
		check.clear();
		priority_queue<info> q;
		q.push({ 0, 0, 0 });
		while(!q.empty()) {
			auto [nowx, nowy, nowcheese] = q.top(); q.pop();
			if(visited[nowx][nowy]) continue;
			visited[nowx][nowy] = true;
			if(a[nowx][nowy] == 1) {
				if(visited[nowx - 1][nowy] * (1 - a[nowx - 1][nowy]) + visited[nowx + 1][nowy] * (1 - a[nowx + 1][nowy]) + visited[nowx][nowy + 1] * (1 - a[nowx][nowy + 1]) + visited[nowx][nowy - 1] * (1 - a[nowx][nowy - 1]) >= 2) {
					check.emplace_back(nowx, nowy);
				} continue;
			}
			if(nowx && !visited[nowx - 1][nowy]) {
				q.push({ nowx - 1, nowy, a[nowx - 1][nowy] });
			}
			if(nowy && !visited[nowx][nowy - 1]) {
				q.push({ nowx, nowy - 1, a[nowx][nowy - 1] });
			}
			if(nowx < n - 1 && !visited[nowx + 1][nowy]) {
				q.push({ nowx + 1, nowy, a[nowx + 1][nowy] });
			}
			if(nowy < m - 1 && !visited[nowx][nowy + 1]) {
				q.push({ nowx, nowy + 1, a[nowx][nowy + 1] });
			}
		}
	} while(!check.empty());
	cout << time;
}