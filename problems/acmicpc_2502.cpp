#include <stdio.h>
using ll = long long;
int main() {
	int d, k;
	scanf("%d%d", &d, &k);
	ll *a[2];
	a[0] = new ll[d + 1]();
	a[1] = new ll[d + 1]();
	a[0][1] = a[1][2] = 1;
	for(int i = 3; i <= d; i++) {
		a[0][i] = a[0][i - 1] + a[0][i - 2];
		a[1][i] = a[1][i - 1] + a[1][i - 2];
	}
	ll B = 0;
	ll A;
	do {
		B++;
		A = (k - B * a[1][d]) / a[0][d];
	} while(A > B || B * a[1][d] + A * a[0][d] != k);
	printf("%lld\n%lld", A, B);
	return 0;
}