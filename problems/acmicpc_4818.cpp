#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		if(!n) return 0;
		auto a = new int[n];
		int sum = 0;
		int m = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			m = max(m, a[i]);
		} cout << (sum * 2 <= 50) * (1 + 50 / m) << ' ' << (sum * 2 <= 60) * (1 + 60 / m) << ' ' << (sum * 2 <= 70) * (1 + 70 / m) << '\n';
		delete[] a;
	}
}