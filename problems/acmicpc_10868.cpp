#include <stdio.h>
using ll = long long;
ll init(ll *t, ll const *a, ll tidx, ll left, ll right) {
	if(left == right) return t[tidx] = a[left];
	auto const m = (left + right) / 2;
	auto const x = init(t, a, tidx * 2, left, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, right);
	return t[tidx] = (x < y ? x : y);
}
ll min(ll const *t, ll const *a, ll tidx, ll start, ll end, ll left, ll right) {
	if(left > end || right < start) return 2000000000;
	if(start <= left && right <= end) return t[tidx];
	auto const m = (left + right) / 2;
	auto const x = min(t, a, tidx * 2, start, end, left, m);
	auto const y = min(t, a, tidx * 2 + 1, start, end, m + 1, right);
	return x < y ? x : y;
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
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", min(t, a, 1, x, y, 1, n));
	}
}