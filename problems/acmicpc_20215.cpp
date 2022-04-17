#include <cmath>
#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%.12Lf", a + b - sqrtl(a * a + b * b));
}