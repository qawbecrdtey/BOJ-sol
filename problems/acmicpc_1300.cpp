#include <stdio.h>
int main() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	long long l = 1, r = n * n;
	long long res = n * n;
	while(l < r) {
		auto const m = (l + r) / 2;
		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			auto x = m / i;
			if(x > n) x = n;
			sum += x;
		}
		if(sum < k) l = m + 1;
		else {
			res = m;
			r = m;
		}
	}
	printf("%lld", res);
}