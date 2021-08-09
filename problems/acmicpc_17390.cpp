#include <stdio.h>
#include <algorithm>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n + 1]();
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", a[y] - a[x - 1]);
	}
}