#include <stdio.h>
int main() {
	long long n; scanf("%lld", &n);
	printf(n % 7 == 2 || n % 7 == 0 ? "CY" : "SK");
}