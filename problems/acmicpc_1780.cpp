#include <stdio.h>
struct s {
	int p, n, z;
};
void f(int n, int **a, int x, int y, s &r) {
	auto const c = a[x][y];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(c != a[x + i][y + j]) {
				f(n / 3, a, x, y, r);
				f(n / 3, a, x + n / 3, y, r);
				f(n / 3, a, x + n / 3 * 2, y, r);
				f(n / 3, a, x, y + n / 3, r);
				f(n / 3, a, x + n / 3, y + n / 3, r);
				f(n / 3, a, x + n / 3 * 2, y + n / 3, r);
				f(n / 3, a, x, y + n / 3 * 2, r);
				f(n / 3, a, x + n / 3, y + n / 3 * 2, r);
				f(n / 3, a, x + n / 3 * 2, y + n / 3 * 2, r);
				return;
			}
		}
	}
	if(c == 1) r.p++;
	if(c == 0) r.z++;
	if(c == -1) r.n++;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	s r = {0, 0, 0};
	f(n, a, 0, 0, r);
	printf("%d\n%d\n%d", r.n, r.z, r.p);
}