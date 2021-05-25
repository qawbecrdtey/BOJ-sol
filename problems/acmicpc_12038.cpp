#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; t++) {
		printf("Case #%d: ", t);
		long long c, v, l;
		scanf("%lld%lld%lld", &c, &v, &l);
		auto a = new long long[l + 1];
		a[0] = 1;
		for(int i = 1; i <= l; i++) {
			a[i] = (a[i - 1] * v) % 1000000007;
			if(i > 1) {
				a[i] = (a[i] + (((a[i - 2] * c) % 1000000007) * v) % 1000000007) % 1000000007;
			}
		}
		printf("%lld\n", a[l]);
		delete[] a;
	}
}