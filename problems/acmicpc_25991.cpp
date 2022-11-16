#include <cmath>
#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	long double sum = 0;
	for(int i = 0; i < n; i++) { long double x; scanf("%Lf", &x); sum += x * x * x; }
	printf("%.12Lf", powl(sum, 1.0L / 3));

}