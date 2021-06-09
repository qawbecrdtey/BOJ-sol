#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new long long[2000001]();
	int max = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
		if(max < x) max = x;
	}
	long long res = 0;
	for(int i = 1; i <= max; i++) {
		long long cnt = 0;
		for(int j = i; j <= max; j += i) {
			cnt += a[j];
		}
		if(cnt > 1 && res < cnt * i) res = cnt * i;
	}
	printf("%lld", res);
	delete[] a;
}