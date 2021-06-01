#include <stdio.h>
using ll = long long;
ll init(ll *t, ll const *a, ll tidx, ll l, ll r) {
	if(l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x * y) % 1000000007;
}
ll update(ll *t, ll *a, ll tidx, ll y, ll z, ll l, ll r) {
	if(y < l || y > r) return t[tidx];
	if(l == r) return t[tidx] = a[l] = z;
	auto const m = (l + r) / 2;
	auto const left = update(t, a, tidx * 2, y, z, l, m);
	auto const right = update(t, a, tidx * 2 + 1, y, z, m + 1, r);
	return t[tidx] = (left * right) % 1000000007;
}
ll mul(ll *t, ll const *a, ll tidx, ll start, ll end, ll l, ll r) {
	if(end < l || start > r) return 1;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mul(t, a, tidx * 2, start, end, l, m);
	auto const y = mul(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return (x * y) % 1000000007;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	m += k;
	auto a = new ll[n + 1];
	auto t = new ll[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	init(t, a, 1, 1, n);
	while(m--) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if(x == 1) {
			update(t, a, 1, y, z, 1, n);
		}
		else {
			printf("%lld\n", mul(t, a, 1, y, z, 1, n));
		}
	}
}