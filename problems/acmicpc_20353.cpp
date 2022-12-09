#include <cmath>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long double x; cin >> x; cout.precision(12); cout << fixed << 4 * sqrtl(x);
}