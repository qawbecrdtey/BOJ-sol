#include <stdio.h>
using ll = long long;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int idx = 0;
	ll res = 0;
	for(int i = 1; i <= n; i++) {
		ll sum = 0;
		for(int j = i; j <= n; j += i) {
			sum += a[j];
		}
		if(!idx || res < sum) {
			idx = i;
			res = sum;
		}
	}
	if(res < 0) printf("0 0");
	else printf("%d %lld", idx, res);
}