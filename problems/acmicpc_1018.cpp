#include <stdio.h>
int f(char **a, int x, int y, int c) {
	int res = 0;
	for(int i = x; i < x + 8; i++) {
		for(int j = y; j < y + 8; j++) {
			if((c + i + j) % 2 != (a[i][j] == 'W')) {
				res++;
			}
		}
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		scanf("%s", a[i]);
	}
	int min = 10000000;
	for(int i = 0; i <= n - 8; i++) {
		for(int j = 0; j <= m - 8; j++) {
			int x = f(a, i, j, 0);
			int y = f(a, i, j, 1);
			if(min > x) min = x;
			if(min > y) min = y;
		}
	}
	printf("%d", min);
}