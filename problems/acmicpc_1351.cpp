#include <stdio.h>
#include <map>
using namespace std;
using ll = long long;
ll f(map<ll, ll> &m, ll n, ll p, ll q) {
	if(m.find(n) != m.end()) return m[n];
	return m[n] = f(m, n / p, p, q) + f(m, n / q, p, q);
}
int main() {
	ll n, p, q;
	scanf("%lld%lld%lld", &n, &p, &q);
	map<ll, ll> m;
	m[0] = 1;
	printf("%lld", f(m, n, p, q));
}