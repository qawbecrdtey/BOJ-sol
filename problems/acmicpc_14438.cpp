#include <stdio.h>
int init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x < y ? x : y);
}
int update(int *t, int *a, int tidx, int dst, int val, int l, int r) {
	if(dst < l || dst > r) return t[tidx];
	if(l == r) return t[tidx] = a[dst] = val;
	auto const m = (l + r) / 2;
	auto const x = update(t, a, tidx * 2, dst, val, l, m);
	auto const y = update(t, a, tidx * 2 + 1, dst, val, m + 1, r);
	return t[tidx] = (x < y ? x : y);
}
int min(int *t, int const *a, int tidx, int start, int end, int l, int r) {
	if(r < start || end < l) return 1000000001;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = min(t, a, tidx * 2, start, end, l, m);
	auto const y = min(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x < y ? x : y;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new int[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	int m;
	scanf("%d", &m);
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1) {
			update(t, a, 1, y, z, 1, n);
		}
		else {
			printf("%d\n", min(t, a, 1, y, z, 1, n));
		}
	}
}