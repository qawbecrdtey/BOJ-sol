#include <queue>
#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	queue<pair<int, int>> q;
	auto visited = new bool[n]();
	q.push({ x, 0 });
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.first]) continue;
		visited[now.first] = true;
		if (now.first == y) {
			printf("%d", now.second);
			return 0;
		}
		for (int i = now.first % a[now.first]; i < n; i += a[now.first]) {
			if (!visited[i]) q.push({ i, now.second + 1 });
		}
	}
	printf("-1");
}