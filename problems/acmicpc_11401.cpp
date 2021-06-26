#include <stdio.h>
using ll = long long;
constexpr ll p = 1000000007;
ll power(ll a, int b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	auto const r = power(a, b / 2);
	return (((r * r) % p) * power(a, b % 2)) % p;
}
ll inv(ll x) {
	if(x == 1) return 1;
	return power(x, p - 2);
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll res = 1, den = 1;
	for(int i = 1; i <= n; i++) {
		res = (res * i) % p;
	}
	for(int i = 1; i <= k; i++) {
		den = (den * i) % p;
	}
	for(int i = 1; i <= n - k; i++) {
		den = (den * i) % p;
	}
	res = (res * inv(den)) % p;
	printf("%lld", res);
}