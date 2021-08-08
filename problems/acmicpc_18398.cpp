#include <stdio.h>
using ll = long long;
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		while(n--) {
			ll a, b;
			scanf("%lld%lld", &a, &b);
			printf("%lld %lld\n", a + b, a * b);
		}
	}
}