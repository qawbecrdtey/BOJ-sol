#include <stdio.h>
using ll = long long;
ll n(ll x) {
	int i = 1;
	while(x < 0) x += (1000000007 << i);
	return x % 1000000007;
}
ll inv(ll *a, int x) {
	if(a[x]) return a[x];
	return a[x] = n(-(1000000007 / x) * inv(a, 1000000007 % x));
}
int main() {
	int n, r;
	scanf("%d%d", &n, &r);
	auto a = new ll[n + 1]();
	a[1] = 1;
	ll res = 1;
	for(int i = 1; i <= n; i++) {
		res = (res * i) % 1000000007;
	}
	for(int i = 1; i <= r; i++) {
		res = (res * inv(a, i)) % 1000000007;
	}
	for(int i = 1; i <= n - r; i++) {
		res = (res * inv(a, i)) % 1000000007;
	}
	printf("%lld", res);
}