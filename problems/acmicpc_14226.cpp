#include <cstdio>
#include <queue>
struct info { int x, y, time; };
int main() {
	bool visited[2010][2010]{};
	int n; scanf("%d", &n);
	std::queue<info> q; q.push({ 1, 0, 0 });
	while(!q.empty()) {
		auto const [x, y, time] = q.front(); q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = true;
		if(x == n) {
			printf("%d", time);
			return 0;
		}
		if(!visited[x][x]) q.push({ x, x, time + 1 });
		if(y && x + y < 2010 && !visited[x + y][y]) q.push({ x + y, y, time + 1 });
		if(x && !visited[x - 1][y]) q.push({ x - 1, y, time + 1 });
	}
}