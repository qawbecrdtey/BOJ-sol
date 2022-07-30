#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, a; cin >> n >> m >> a;
	auto arr = new int*[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int tot = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			tot += (arr[i][j] * 2 < arr[i + 1][j]);
		}
	} cout << tot * a;
}