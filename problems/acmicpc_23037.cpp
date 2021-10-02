#include <stdio.h>
int power(int n) {
	auto const r = n * n;
	return r * r * n;
}
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	while(n) {
		sum += power(n % 10);
		n /= 10;
	}
	printf("%d", sum);
}