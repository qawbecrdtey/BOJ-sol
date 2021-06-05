#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	int s;
	scanf("%d", &s);
	auto lo = std::lower_bound(a, a + n, s);
	if(*lo == s) {
		printf("0");
		return 0;
	}
	if(lo == a) {
		long long x = s;
		long long y = *lo - s;
		printf("%lld", x * y - 1);
		return 0;
	}
	long long x = s - *(lo - 1);
	long long y = *lo - s;
	printf("%lld", x * y - 1);
}