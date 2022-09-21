#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case " << tt << ": ";
		int n, m; cin >> n >> m; cout << m - (n - 1) << '\n';
	}
}