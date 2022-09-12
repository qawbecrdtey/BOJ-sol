#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll k, a, b; cin >> k >> a >> b;
	ll x = (1000000000000000000 + 2 * k - 1) / k * k;
	a += x, b += x;
	cout << b / k - (a - 1) / k;
}