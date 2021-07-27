#include <stdio.h>
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll b) {
	if(!b) return 1;
	if(b == 1) return a;
	auto const r = power(a, b / 2);
	return (((r * r) % M) * power(a, b % 2)) % M;
}
inline ll inv(ll x) {
	return power(x, M - 2);
}
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll res = 1, den = 1;
	for(ll i = m + 1; i <= n; i++) {
		res = (res * i) % M;
	}
	for(ll i = 1; i <= n - m; i++) {
		den = (den * i) % M;
	}
	printf("%lld", (res * inv(den)) % M);
}