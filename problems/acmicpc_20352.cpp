#include <cmath>
#include <cstdio>
using ld = long double;
int main() {
	ld x; scanf("%Lf", &x);
	printf("%.12Lf", 2 * sqrtl(x * M_PIl));
}