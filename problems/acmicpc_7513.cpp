#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Scenario #" << tt << ":\n";
		int n; cin >> n; auto a = new string[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		} int m; cin >> m; while(m--) {
			int k; cin >> k; while(k--) {
				int x; cin >> x; cout << a[x];
			} cout << '\n';
		} cout << '\n';
		delete[] a;
	}
}