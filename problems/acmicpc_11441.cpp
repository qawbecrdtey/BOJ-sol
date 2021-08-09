#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1]();
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}
	int m;
	scanf("%d", &m);
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", a[y] - a[x - 1]);
	}
}