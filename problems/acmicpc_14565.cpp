#include <stdio.h>
using ll = long long;
using lll = __int128;
ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b, a % b);
}
ll phi(ll n) {
	ll res = n;
	for(ll i = 2; i * i <= n; i++) {
		bool flag = false;
		while(n % i == 0) {
			flag = true;
			n /= i;
		}
		if(flag) {
			res /= i;
			res *= i - 1;
		}
	}
	if(n > 1) {
		res /= n;
		res *= n - 1;
	}
	return res;
}
lll power(lll a, lll n, lll m) {
	if(!n) return 1;
	if(n == 1) return a % m;
	auto const r = power(a, n / 2, m);
	return ((r * r) % m * power(a, n % 2, m)) % m;
}
inline ll inv(ll a, ll b) { return (ll)power(b, phi(a) - 1, a); }
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	printf("%lld ", n - m);
	if(gcd(n, m) != 1) {
		printf("-1");
		return 0;
	}
	printf("%lld", inv(n, m));
}