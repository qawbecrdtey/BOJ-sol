#include <stdio.h>
#include <math.h>
int main() {
	long double a, b, c;
	scanf("%Lf%Lf%Lf", &a, &b, &c);
	long double l = 0, r = a > b ? b : a;
	while(l < r && (r - l) >= 0.000001) {
		auto const m = (l + r) / 2;
		if(1 / sqrt(a * a - m * m) + 1 / sqrt(b * b - m * m) <= 1 / c) l = m;
		else r = m;
	}
	printf("%Lf", (l + r) / 2);
}