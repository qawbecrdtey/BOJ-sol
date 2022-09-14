#include <iostream>
using namespace std;
int fold(int *a, int n) {
	for(int i = 0; i < (n + 1) / 2; i++) {
		a[i] += a[n - i - 1];
	} return (n + 1) / 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		int n; cin >> n;
		auto a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		while(n > 2) n = fold(a, n);
		cout << "Case #" << tt << ": " << (a[0] > a[1] ? "Alice\n" : "Bob\n");
		delete[] a;
	}
}