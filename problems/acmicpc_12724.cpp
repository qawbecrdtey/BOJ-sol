#include <algorithm>
#include <stdio.h>
using ll = long long;
int main() {
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		printf("Case #%d: ", tt);
		int n;
		scanf("%d", &n);
		auto a = new ll[n];
		auto b = new ll[n];
		for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
		for(int i = 0; i < n; i++) scanf("%lld", &b[i]);
		std::sort(a, a + n);
		std::sort(b, b + n);
		ll res = 0;
		for(int i = 0; i < n; i++) res += a[i] * b[n - i - 1];
		printf("%lld\n", res);
		delete[] a;
		delete[] b;
	}
}