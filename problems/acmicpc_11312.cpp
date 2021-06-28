#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (a / b) * (a / b));
	}
}