#include <iostream>
#include <string>
using namespace std;
inline void flip(string *a, int x, int y) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			a[x + i][y + j] = (char)('0' + '1' - a[x + i][y + j]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, cnt = 0; cin >> n >> m;
	auto a = new string[n];
	auto b = new string[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n - 2; i++) {
		for(int j = 0; j < m - 2; j++) {
			if(a[i][j] != b[i][j]) {
				flip(a, i, j);
				cnt++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	} cout << cnt;
}