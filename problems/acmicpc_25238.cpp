#include <cstdio>
int main() {
	double a, b; scanf("%lf%lf", &a, &b);
	printf("%d", a / 100 * (100 - b) < 100);
}