#include <stdio.h>
#include <math.h>
int main() {
	long double a, b;
	scanf("%Lf%Lf", &a, &b);
	printf("%.18Lf", 1 / (1 + pow(10, (b - a) / 400)));
}