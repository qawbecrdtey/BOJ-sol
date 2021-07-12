#include <stdio.h>
using ull = unsigned long long;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ull[n + 1]();
	a[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			a[i] += a[j] * a[i - j - 1];
		}
	}
	printf("%llu", a[n]);
	delete[] a;
}