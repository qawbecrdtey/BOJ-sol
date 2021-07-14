#include <stdio.h>
using ll = long long;
constexpr ll p = 1000000007;
ll power(ll n, ll m) {
	if(m == 0) return 1;
	if(m == 1) return n;
	ll const r = power(n, m / 2);
	return (((r * r) % p) * power(n, m % 2)) % p;
}
inline ll inv(ll n) { return power(n % p, p - 2); }
int main() {
	int m;
	auto fact = new ll[4000001]();
	fact[0] = 1;
	for(int i = 1; i <= 4000000; i++) {
		fact[i] = (i * fact[i - 1]) % p;
	}
	scanf("%d", &m);
	while(m--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%lld\n", (fact[n] * inv((fact[k] * fact[n - k]) % p)) % p);
	}
	delete[] fact;
}