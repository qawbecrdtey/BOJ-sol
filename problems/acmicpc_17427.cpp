#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long res = 0;
	for(int i = 1; i <= n; i++) {
		res += i * (n / i);
	}
	printf("%lld", res);
}