#include <cstdio>
int main() {
	long long k, n; scanf("%lld%lld", &k, &n);
	if(n == 1) { printf("-1"); return 0; }
	printf("%lld", (k * n + (n - 2)) / (n - 1));
}