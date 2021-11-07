#include <stdio.h>
int main() {
	long long n;
	scanf("%lld", &n);
	printf(n & 1 ? "SK" : "CY");
}