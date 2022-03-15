#include <iostream>
using namespace std;
inline int sum(int const *sarr, int l, int r) {
	// l <= x <= r
	return sarr[r + 1] - sarr[l];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto arr = new int[n];
		auto sarr = new int[n + 1]; sarr[0] = 0;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			sarr[i + 1] = sarr[i] + arr[i];
		}
		auto a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			a[i][i] = arr[i];
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n - i; j++) {
				int const s = sum(sarr, j, j + i);
				a[j][j + i] = max(s - a[j + 1][j + i], s - a[j][j + i - 1]);
			}
		}
		cout << a[0][n - 1] << '\n';
		for(int i = 0; i < n; i++) delete[] a[i];
		delete[] a;
		delete[] sarr;
		delete[] arr;
	}
}