#include <iostream>
#include <queue>
using namespace std;
struct info { int x, y, z, t; };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int m, n, h; cin >> m >> n >> h;
	auto a = new int**[h];
	auto time = new int**[h];
	for(int i = 0; i < h; i++) {
		a[i] = new int*[n];
		time[i] = new int*[n];
		for(int j = 0; j < n; j++) {
			a[i][j] = new int[m];
			time[i][j] = new int[m];
			fill(time[i][j], time[i][j] + m, -1);
			for(int k = 0; k < m; k++) {
				cin >> a[i][j][k];
			}
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				if(a[i][j][k] == 1) {
					queue<info> q;
					q.push({ i, j, k, 0 });
					while(!q.empty()) {
						auto [nowi, nowj, nowk, nowt] = q.front(); q.pop();
						if(a[nowi][nowj][nowk] == -1 || (time[nowi][nowj][nowk] != -1 && time[nowi][nowj][nowk] <= nowt)) continue;
						time[nowi][nowj][nowk] = nowt;
						if(nowi && a[nowi - 1][nowj][nowk] != -1 && (nowt + 1 < time[nowi - 1][nowj][nowk] || time[nowi - 1][nowj][nowk] == -1)) {
							q.push({ nowi - 1, nowj, nowk, nowt + 1 });
						}
						if(nowj && a[nowi][nowj - 1][nowk] != -1 && (nowt + 1 < time[nowi][nowj - 1][nowk] || time[nowi][nowj - 1][nowk] == -1)) {
							q.push({ nowi, nowj - 1, nowk, nowt + 1 });
						}
						if(nowk && a[nowi][nowj][nowk - 1] != -1 && (nowt + 1 < time[nowi][nowj][nowk - 1] || time[nowi][nowj][nowk - 1] == -1)) {
							q.push({ nowi, nowj, nowk - 1, nowt + 1 });
						}
						if(nowi < h - 1 && a[nowi + 1][nowj][nowk] != -1 && (nowt + 1 < time[nowi + 1][nowj][nowk] || time[nowi + 1][nowj][nowk] == -1)) {
							q.push({ nowi + 1, nowj, nowk, nowt + 1 });
						}
						if(nowj < n - 1 && a[nowi][nowj + 1][nowk] != -1 && (nowt + 1 < time[nowi][nowj + 1][nowk] || time[nowi][nowj + 1][nowk] == -1)) {
							q.push({ nowi, nowj + 1, nowk, nowt + 1 });
						}
						if(nowk < m - 1 && a[nowi][nowj][nowk + 1] != -1 && (nowt + 1 < time[nowi][nowj][nowk + 1] || time[nowi][nowj][nowk + 1] == -1)) {
							q.push({ nowi, nowj, nowk + 1, nowt + 1 });
						}
					}
				}
			}
		}
	}
	int max = 0;
	for(int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if(time[i][j][k] == -1) {
					if(a[i][j][k] == -1) continue;
					cout << "-1";
					return 0;
				}
				if(max < time[i][j][k]) max = time[i][j][k];
			}
		}
	}
	cout << max;
}