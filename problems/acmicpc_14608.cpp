#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(12);
	long double a, b, c; cin >> a >> b >> c; cin >> a >> b >> c;
	cout << fixed << (b - a) / (c * 2);
}