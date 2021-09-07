#include <algorithm>
#include <stdio.h>
using ll = long long;
int main() {
	ll d, p, q;
	scanf("%lld%lld%lld", &d, &p, &q);
	if (p < q) std::swap(p, q);
	ll min = (d + p - 1) / p * p;
	for (ll i = 0; i < q && i * p <= d; i++) {
		auto const x = (d - i * p + q - 1) / q * q + i * p;
		if (min > x) min = x;
	}
	printf("%lld", min);
}