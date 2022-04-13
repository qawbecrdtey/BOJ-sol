#include <iostream>
using namespace std;
int main() {
	cout.precision(12);
	cout << fixed;
	double a, b, c;
	cin >> a >> b >> c;
	cout << (a * 229 * 324 * 2 + b * 297 * 420 * 2 + c * 210 * 297) / 1000000;
}