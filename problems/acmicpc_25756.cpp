#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long double v = 0;
	cout.precision(12);
	int n; cin >> n; while(n--) {
		long double a; cin >> a; a /= 100;
		cout << fixed << (v = 1 - (1 - v) * (1 - a)) * 100 << '\n';
	}
}