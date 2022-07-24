#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed;
	cout.precision(12);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		int n; cin >> n;
		auto a = new long double[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 1; i < n - 1; i++) if(a[i] > (a[i - 1] + a[i + 1]) / 2) a[i] = (a[i - 1] + a[i + 1]) / 2;
		cout << a[n - 2] << '\n';
		delete[] a;
	}
}