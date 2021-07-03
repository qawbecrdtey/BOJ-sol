#include <stdio.h>
#include <algorithm>
using ll = long long;
ll update(ll *t, ll *a, int tidx, int y, int z, int l, int r) {
	if(y < l || y > r) return t[tidx];
	if(l == r) return t[tidx] = a[l] = z;
	auto const m = (l + r) / 2;
	auto const left = update(t, a, tidx * 2, y, z, l, m);
	auto const right = update(t, a, tidx * 2 + 1, y, z, m + 1, r);
	return t[tidx] = left + right;
}
ll sum(ll const *t, ll const *a, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, a, tidx * 2, start, end, l, m);
	auto const y = sum(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new ll[n + 1]();
	auto t = new ll[n * 4]();
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(x) {
			update(t, a, 1, y, z, 1, n);
		}
		else {
			if(y > z) std::swap(y, z);
			printf("%lld\n", sum(t, a, 1, y, z, 1, n));
		}
	}
	delete[] a;
	delete[] t;
}