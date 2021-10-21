#include <iostream>
using ll = long long;
ll sqrt(ll n) {
	ll l = 0, r = n + 1, res = 0;
	while(l < r) {
		auto const m = (l + r) / 2;
		if(m * m == n) return m;
		if(m * m > n) {
			r = m;
		}
		else {
			res = m;
			l = m + 1;
		}
	}
	return res;
}
int main() {
	ll n; std::cin >> n;
	std::cout << sqrt(n);
}