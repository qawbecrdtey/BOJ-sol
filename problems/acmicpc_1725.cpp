#include <stdio.h>
using ll = long long;
int init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] > a[y] ? y : x);
}
int min(int *t, int *a, int tidx, int start, int end, int l, int r) {
	if(start > r || end < l) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = min(t, a, tidx * 2, start, end, l, m);
	auto const y = min(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[x] > a[y] ? y : x;
}
ll find(int *t, int *a, int const n, int l, int r) {
	if(l > r) return 0;
	if(l == r) return a[l];
	auto const m = min(t, a, 1, l, r, 1, n);
	auto const x = find(t, a, n, l, m - 1);
	auto const y = find(t, a, n, m + 1, r);
	ll res = a[m] * (ll)(r - l + 1);
	if(res < x) res = x;
	if(res < y) res = y;
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new int[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	init(t, a, 1, 1, n);
	printf("%lld", find(t, a, n, 1, n));
}