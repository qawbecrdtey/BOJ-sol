#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int x, y; cin >> x >> y;
		struct info{int x, y, c;};
		queue<info> q; q.push({x, y, 0});
		auto visited = new bool*[500];
		for(int i = 0; i < 500; i++) {
			visited[i] = new bool[500]();
		}
		while(!q.empty()) {
			auto [nowx, nowy, nowc] = q.front(); q.pop();
			if(visited[nowx][nowy]) continue;
			visited[nowx][nowy] = true;
			if(nowx == nowy) {
				cout << nowc << '\n';
				break;
			}
			if(!visited[nowx + 1][nowy]) q.push({nowx + 1, nowy, nowc + 1});
			if(!visited[nowx << 1][nowy + 3] && (nowx << 1) <= nowy + 3) q.push({ (nowx << 1), nowy + 3, nowc + 1});
		}
		for(int i = 0; i < 500; i++) delete[] visited[i];
		delete[] visited;
	}
}