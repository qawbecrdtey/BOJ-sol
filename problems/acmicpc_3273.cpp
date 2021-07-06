#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int x;
	scanf("%d", &x);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] * 2 >= x) break;
		auto const it = std::lower_bound(a + i, a + n, x - a[i]);
		if(*it != x - a[i]) continue;
		cnt++;
	}
	printf("%d", cnt);
	delete[] a;
}