#include <cmath>
#include <cstdio>
int main() {
	long double x;
	scanf("%Lf", &x);
	printf("%.9Lf", 4 * sqrtl(x));
}