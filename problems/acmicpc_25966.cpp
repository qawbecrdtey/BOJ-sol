#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, q; cin >> n >> m >> q;
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while(q--) {
		int x, y, z; cin >> x >> y >> z;
		switch(x) {
			case 0: cin >> a[y][z]; break;
			case 1: swap(a[y], a[z]); break;
			default: __builtin_unreachable();
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		} cout << '\n';
	}
}