#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	auto arr = new int*[n];
	struct info { int x, y, d; };
	queue<info> q;
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m];
		fill(arr[i], arr[i] + m, 999999999);
		cin >> a[i];
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '1') {
				q.push({ i, j, 0 });
			}
		}
	}
	while(!q.empty()) {
		auto [nowx, nowy, nowd] = q.front(); q.pop();
		if(arr[nowx][nowy] <= nowd) continue;
		arr[nowx][nowy] = nowd;
		if(nowx && arr[nowx - 1][nowy] > nowd + 1) q.push({ nowx - 1, nowy, nowd + 1 });
		if(nowy && arr[nowx][nowy - 1] > nowd + 1) q.push({ nowx, nowy - 1, nowd + 1 });
		if(nowx < n - 1 && arr[nowx + 1][nowy] > nowd + 1) q.push({ nowx + 1, nowy, nowd + 1 });
		if(nowy < m - 1 && arr[nowx][nowy + 1] > nowd + 1) q.push({ nowx, nowy + 1, nowd + 1 });
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		} cout << '\n';
	}
}