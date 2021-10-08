#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, t;
	cin >> n >> t;
	auto a = new int*[n + 1];
	a[0] = new int[t + 1]();
	for(int i = 1; i <= n; i++) {
		a[i] = new int[t + 1]();
		int k, s;
		cin >> k >> s;
		for(int j = 0; j < k && j <= t; j++) {
			a[i][j] = a[i - 1][j];
		}
		for(int j = k; j <= t; j++) {
			a[i][j] = a[i - 1][j];
			if(a[i - 1][j - k] + s > a[i][j]) a[i][j] = a[i - 1][j - k] + s;
		}
	}
	cout << a[n][t];
}