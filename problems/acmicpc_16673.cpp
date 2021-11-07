#include <stdio.h>
int main() {
	long long c, k, p;
	scanf("%lld%lld%lld", &c, &k, &p);
	printf("%lld", k * (c * (c + 1) / 2) + p * (c * (c + 1) * (2 * c + 1) / 6));
}