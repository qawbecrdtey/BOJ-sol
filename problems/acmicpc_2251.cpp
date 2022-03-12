#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> a >> b >> c;
	auto visited = new bool*[a + 1];
	for(int i = 0; i <= a; i++) visited[i] = new bool[b + 1]();
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while(!q.empty()) {
		auto const [x, y] = q.front(); q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = true;
		int nextx = x + y, nexty = x + y;
		if(nextx > a) nextx = a;
		if(nexty > b) nexty = b;
		if(!visited[nextx][x + y - nextx]) q.push({ nextx, x + y - nextx });
		if(!visited[x + y - nexty][nexty]) q.push({ x + y - nexty, nexty });
		nextx = c - y, nexty = c - x;
		if(nextx > a) nextx = a;
		if(nexty > b) nexty = b;
		if(!visited[nextx][y]) q.push({ nextx, y });
		if(!visited[x][nexty]) q.push({ x, nexty });
		if(!visited[0][y]) q.push({ 0, y });
		if(!visited[x][0]) q.push({ x, 0 });
	}
	for(int i = b; i >= 0; i--) {
		if(visited[0][i]) cout << c - i << ' ';
	}
}