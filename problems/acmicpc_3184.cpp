#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int r, c; cin >> r >> c;
	auto a = new char*[r];
	for(int i = 0; i < r; i++) {
		a[i] = new char[c + 1];
		cin >> a[i];
	}
	int res[2]{};
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(a[i][j] != '#') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				int val[2]{};
				while(!q.empty()) {
					auto const [nowi, nowj] = q.front(); q.pop();
					if(a[nowi][nowj] == '#') continue;
					val[0] += (a[nowi][nowj] == 'o');
					val[1] += (a[nowi][nowj] == 'v');
					a[nowi][nowj] = '#';
					if(nowi && a[nowi - 1][nowj] != '#') {
						q.push({ nowi - 1, nowj });
					}
					if(nowj && a[nowi][nowj - 1] != '#') {
						q.push({ nowi, nowj - 1 });
					}
					if(nowi < r - 1 && a[nowi + 1][nowj] != '#') {
						q.push({ nowi + 1, nowj });
					}
					if(nowj < c - 1 && a[nowi][nowj + 1] != '#') {
						q.push({ nowi, nowj + 1 });
					}
				}
				if(val[0] > val[1]) res[0] += val[0];
				else res[1] += val[1];
			}
		}
	}
	cout << res[0] << ' ' << res[1];
}