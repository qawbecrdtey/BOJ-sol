#include <cstdio>
int main() {
	long long a, d, k; scanf("%lld%lld%lld", &a, &d, &k);
	if((k - a) / d * d != k - a || (k - a) / d < 0) printf("X");
	else printf("%lld", (k - a) / d + 1);
}