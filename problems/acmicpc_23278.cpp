#include <stdio.h>
#include <algorithm>
int main() {
	int n, l, h;
	scanf("%d%d%d", &n, &l, &h);
	auto a = new int[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	std::sort(a, a + n);
	int sum = 0;
	for(int i = l; i < n - h; i++) {
		sum += a[i];
	} printf("%.12Lf", sum / (long double)(n - h - l));
}