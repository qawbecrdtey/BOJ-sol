#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto a = new char[m + 1];
		for(int i = 0; i < n; i++) {
			cin >> a;
			for(int j = m - 1; j >= 0; j--) {
				cout << a[j];
			} cout << '\n';
		}
		delete[] a;
	}
}