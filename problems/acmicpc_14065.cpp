#include <iostream>
using namespace std;
int main() {
	long double x; cin >> x;
	cout << fixed;
	cout.precision(12);
	cout << (1 / x) * (100000.0L / 1609.344L) * 3.785411784L;
}