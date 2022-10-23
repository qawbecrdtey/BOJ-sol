#include <iostream>
#include <queue>
using namespace std;
struct info {
	int h, x, y;
	[[nodiscard]] bool operator<(info const &i) const { return h < i.h; }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	priority_queue<info> pq;
	auto a = new int*[n];
	auto height = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m]();
		height[i] = new int[m]();
		for(int j = 0; j < m; j++) {
			cin >> height[i][j];
			pq.push({ height[i][j], i, j });
		}
	}
	while(!pq.empty()) {
		auto [h, x, y] = pq.top(); pq.pop();
		if(!x && !y) {
			a[x][y] = 1;
			continue;
		}
		if(x && height[x][y] < height[x - 1][y]) a[x][y] += a[x - 1][y];
		if(y && height[x][y] < height[x][y - 1]) a[x][y] += a[x][y - 1];
		if(x < n - 1 && height[x][y] < height[x + 1][y]) a[x][y] += a[x + 1][y];
		if(y < m - 1 && height[x][y] < height[x][y + 1]) a[x][y] += a[x][y + 1];
	} cout << a[n - 1][m - 1];
}