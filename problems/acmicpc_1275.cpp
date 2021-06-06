#include <stdio.h>
using ll = long long;
ll init(ll *t, ll const *a, ll tidx, ll l, ll r) {
	if(l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = x + y;
}
ll sum(ll *t, ll const *a, ll tidx, ll start, ll end, ll l, ll r) {
	if(r < start || l > end) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, a, tidx * 2, start, end, l, m);
	auto const y = sum(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
ll update(ll *t, ll *a, ll tidx, ll x, ll y, ll l, ll r) {
	if(x < l || x > r) return t[tidx];
	if(l == r) return t[tidx] = a[l] = y;
	auto const m = (l + r) / 2;
	auto const left = update(t, a, tidx * 2, x, y, l, m);
	auto const right = update(t, a, tidx * 2 + 1, x, y, m + 1, r);
	return t[tidx] = left + right;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new ll[n + 1];
	auto t = new ll[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > y) { auto i = y; y = x; x = i; }
		printf("%lld\n", sum(t, a, 1, x, y, 1, n));
		scanf("%d%d", &x, &y);
		update(t, a, 1, x, y, 1, n);
	}
}