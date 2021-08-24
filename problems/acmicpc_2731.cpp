#include <stdio.h>
int main() {
	// __int128
	int t;
	scanf("%d", &t);
	while(t--) {
		unsigned long long _n, res = 0;
		scanf("%llu", &_n);
		__int128 n = _n, mul = 1;
		while(mul < n) {
			auto const M = mul * 10;
			for(int i = 0; i < 10; i++) {
				auto const x = res + i * mul;
				if((((x * x) % M) * x) % M == n % M) {
					res = x;
					break;
				}
			}
			mul = M;
		}
		printf("%llu\n", res);
	}
}