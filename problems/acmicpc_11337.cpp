#include <cmath>
#include <iostream>
using namespace std;
inline constexpr long double sqrt2 = 1.4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727350138462309122970249248360L;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(3);
	int t; cin >> t; while(t--) {
		long double r, b; cin >> r >> b;
		cout << fixed << (r * sqrt2 <= b ? 2 * r * r : b * sqrt(4 * r * r - b * b)) << '\n';
	}
}