#include <iostream>
using namespace std;
inline void press(bool **pressed, int **a, int n, int m, int x, int y) {
	if(x) a[x - 1][y] = 1 - a[x - 1][y];
	if(y) a[x][y - 1] = 1 - a[x][y - 1];
	pressed[x][y] = !pressed[x][y], a[x][y] = 1 - a[x][y];
	if(y < m - 1) a[x][y + 1] = 1 - a[x][y + 1];
	if(x < n - 1) a[x + 1][y] = 1 - a[x + 1][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int*[n];
	auto b = new int*[n];
	auto pressed = new bool*[n];
	auto pressed_res = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		b[i] = new int[m];
		pressed[i] = new bool[m];
		pressed_res[i] = new bool[m];
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int res = 123456789;
	for(int x = 0; x < (1 << m); x++) {
		int cur = 0;
		for(int i = 0; i < n; i++) {
			copy(a[i], a[i] + m, b[i]);
			fill(pressed[i], pressed[i] + m, false);
		}
		for(int i = m - 1; i >= 0; i--) {
			if(x & (1 << i)) press(pressed, b, n, m, 0, m - 1 - i), cur++;
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(b[i - 1][j]) press(pressed, b, n, m, i, j), cur++;
			}
		}
		bool flag = false;
		for(int i = 0; i < m; i++) {
			if(b[n - 1][i]) {
				flag = true;
				break;
			}
		}
		if(flag) continue;
		if(cur < res) {
			for(int i = 0; i < n; i++) {
				copy(pressed[i], pressed[i] + m, pressed_res[i]);
			} res = cur;
		}
	}
	if(res == 123456789) cout << "IMPOSSIBLE";
	else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << pressed_res[i][j] << ' ';
			} cout << '\n';
		}
	}
}