#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int*[n + 1];
	for(int i = 1; i <= n; i++) {
		a[i] = new int[n + 1]();
	}
	while(true) {
		int x, y;
		cin >> x >> y;
		if(x == -1 && y == -1) break;
		a[x][y] = a[y][x] = 1;
	}
	auto arr = new int[n + 1]();
	for(int i = 1; i <= n; i++) {
		if(!arr[i]) {
			queue<pair<int, int>> q;
			q.push({ i, 1 });
			while(!q.empty()) {
				auto const now = q.front(); q.pop();
				if(arr[now.first]) {
					if(arr[now.first] == now.second) continue;
					printf("-1");
					return 0;
				}
				arr[now.first] = now.second;
				for(int j = 1; j <= n; j++) {
					if(a[now.first][j]) continue;
					if(now.first == j) continue;
					q.push( { j, -now.second });
				}
			}
		}
	}
	printf("1\n");
	for(int i = 1; i <= n; i++) {
		if(arr[i] == 1) printf("%d ", i);
	} printf("-1\n");
	for(int i = 1; i <= n; i++) {
		if(arr[i] == -1) printf("%d ", i);
	} printf("-1\n");
}