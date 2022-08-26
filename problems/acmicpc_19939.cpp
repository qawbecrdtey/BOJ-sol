#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	if(n < m * (m + 1) / 2) {
		cout << -1;
		return 0;
	}
	if((n - (m * (m + 1) / 2)) % m == 0) {
		cout << m - 1;
		return 0;
	}
	cout << m;
}