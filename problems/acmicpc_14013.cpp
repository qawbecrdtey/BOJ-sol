#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(12);
	cout << fixed;
	long double x, y; cin >> x >> y;
	int t; cin >> t; while(t--) {
		long double v; char c[2];
		cin >> v >> c;
		if(*c == 'A') cout << v / x * y << '\n';
		else cout << v / y * x << '\n';
	}
}