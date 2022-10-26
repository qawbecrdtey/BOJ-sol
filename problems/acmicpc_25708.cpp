#include <iostream>
#include <limits>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto row = new int[n]();
	auto col = new int[m]();
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	int res = numeric_limits<int>::min();
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = 0; k < m - 1; k++) {
				for(int l = k + 1; l < m; l++) {
					res = max(res, row[i] + row[j] + col[k] + col[l] - a[i][k] - a[j][k] - a[i][l] - a[j][l] + (j - i - 1) * (l - k - 1));
				}
			}
		}
	} cout << res;
}