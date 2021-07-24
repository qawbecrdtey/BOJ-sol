#include <stdio.h>
using ll = long long;
ll update(ll *t, int tidx, int idx, ll val, int l, int r) {
	if(idx < l || r < idx) return t[tidx];
	if(l == r) return t[tidx] += val;
	auto const m = (l + r) / 2;
	auto const x = update(t, tidx * 2, idx, val, l, m);
	auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = x + y;
}
ll sum(ll const *t, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	auto t = new ll[n * 4]();
	while(q--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1) {
			update(t, 1, y, z, 1, n);
		}
		else {
			printf("%lld\n", sum(t, 1, y, z, 1, n));
		}
	}
}