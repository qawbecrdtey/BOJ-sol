#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		long long n, sum = 0;
		scanf("%lld", &n);
		for(long long i = 5; i <= n; i *= 5) sum += n / i;
		printf("%lld\n", sum);
	}
}