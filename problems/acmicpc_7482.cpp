#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; cout.precision(10); while(t--) {
		long double x; cin >> x; cout << fixed << x / 6 << '\n';
	}
}