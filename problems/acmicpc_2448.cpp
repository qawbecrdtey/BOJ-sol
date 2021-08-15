#include <stdio.h>
void f(bool **a, int n, int x, int y) {
	if(n == 3) {
		a[x - 2][y + 2] = true;
		a[x - 1][y + 1] = a[x - 1][y + 3] = true;
		a[x][y] = a[x][y + 1] = a[x][y + 2] = a[x][y + 3] = a[x][y + 4] = true;
		return;
	}
	f(a, n / 2, x, y);
	f(a, n / 2, x, y + n);
	f(a, n / 2, x - n / 2, y + n / 2);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new bool[n << 1]();
	}
	f(a, n, n - 1, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (n << 1); j++) {
			printf(a[i][j] ? "*" : " ");
		} printf("\n");
	}
	delete[] a;
}