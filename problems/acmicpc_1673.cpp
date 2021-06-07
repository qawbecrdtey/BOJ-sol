#include <stdio.h>
int main() {
	long long n, k;
	while(scanf("%lld%lld", &n, &k) != EOF) {
		long long res = 0;
		long long coupon = n;
		long long stamp = 0;
		while(coupon) {
			res += coupon;
			stamp += coupon;
			coupon = stamp / k;
			stamp = stamp % k;
		}
		printf("%lld\n", res);
	}
}