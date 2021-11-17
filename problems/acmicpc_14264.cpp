#include <stdio.h>
int main() {
	long double x = 0.4330127018922194;
	long long n;
	scanf("%lld", &n);
	printf("%.9Lf", n * n * x);
}