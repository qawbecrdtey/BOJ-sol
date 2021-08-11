#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int *a[2];
	a[0] = new int[n + 1]();
	a[1] = new int[n + 1]();
	a[0][1] = 1;
	for(int i = 2; i <= n; i++) {
		a[0][i] = (a[0][i - 1] + a[1][i - 1]) % 10;
		a[1][i] = a[0][i - 1];
	}
	printf("%d", (a[0][n] + a[1][n]) % 10);
}