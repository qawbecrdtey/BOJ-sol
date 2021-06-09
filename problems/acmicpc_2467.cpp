#include <stdio.h>
#include <algorithm>
long long f(long long a) { return a > 0 ? a : -a; }
int main() {
	int n;
	scanf("%d", &n);
	auto a = new long long[n];
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	std::sort(a, a + n);
	int l = 0, r = n - 1;
	int minl = 0, minr = n - 1;
	long long min = f(a[l] + a[r]);
	while(l < r) {
		if(min > f(a[l] + a[r])) min = f(a[minl = l] + a[minr = r]);
		if(a[l] + a[r] == 0) {
			printf("%lld %lld", a[l], a[r]);
			delete[] a;
			return 0;
		}
		if(a[l] + a[r] > 0) r--;
		else if(a[l] + a[r] < 0) l++;
	}
	printf("%lld %lld", a[minl], a[minr]);
	delete[] a;
}