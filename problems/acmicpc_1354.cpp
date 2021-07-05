#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <unordered_map>
using namespace std;
using ll = long long;
ll f(unordered_map<ll, ll> &m, ll n, ll p, ll q, ll x, ll y) {
	if(n < 1) return 1;
	if(m.find(n) != m.end()) return m[n];
	auto const l = f(m, n / p - x, p, q, x, y);
	auto const r = f(m, n / q - y, p, q, x, y);
	return m[n] = l + r;
}
int main() {
	ll n, p, q, x, y;
	scanf("%lld%lld%lld%lld%lld", &n, &p, &q, &x, &y);
	unordered_map<ll, ll> m;
	printf("%lld", f(m, n, p, q, x, y));
}