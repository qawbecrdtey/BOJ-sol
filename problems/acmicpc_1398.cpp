#include <stdio.h>
using ll = long long;
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		ll n;
		scanf("%lld", &n);
		ll sum = 0;
		while(n) {
			auto const m = n % 100;
			auto min = m / 10 + m % 10;
			if (m >= 25 && min > 1 + (m - 25) / 10 + (m - 25) % 10) min = 1 + (m - 25) / 10 + (m - 25) % 10;
			if (m >= 50 && min > 2 + (m - 50) / 10 + (m - 50) % 10) min = 2 + (m - 50) / 10 + (m - 50) % 10;
			if (m >= 75 && min > 3 + (m - 75) / 10 + (m - 75) % 10) min = 3 + (m - 75) / 10 + (m - 75) % 10;
			sum += min;
			n /= 100;
		}
		printf("%lld\n", sum);
	}
}