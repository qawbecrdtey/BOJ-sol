#include <stdio.h>
using ull = unsigned long long;
int main() {
	int n;
	scanf("%d", &n);
	ull sum = 0;
	for(int i = 1; i <= n * 2; i++) {
		sum += i * (((i < n ? i : n) - (i > n ? i - n : 0) + 2) / 2);
	}
	printf("%llu", sum);
}