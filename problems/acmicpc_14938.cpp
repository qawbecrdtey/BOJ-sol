#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	auto d = new int*[n + 1];
	for(int i = 1; i <= n; i++) {
		d[i] = new int[n + 1];
		fill(d[i], d[i] + n + 1, 1000000000);
		d[i][i] = 0;
	}
	while(r--) {
		int x, y, l; cin >> x >> y >> l;
		d[x][y] = min(l, d[x][y]);
		d[y][x] = min(l, d[y][x]);
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) cnt += (d[i][j] <= m) * a[j];
		res = max(res, cnt);
	} cout << res;
}