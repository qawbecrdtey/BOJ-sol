#include <iostream>
using namespace std;
void init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx] = a[l];
		return;
	}
	auto const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m);
	init(t, a, (tidx << 1) | 1, m + 1, r);
	t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
int sum(int const *t, int tidx, int start, int end, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) >> 1;
	auto const x = sum(t, tidx << 1, start, end, l, m);
	auto const y = sum(t, (tidx << 1) | 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	auto t = new int[n << 2];
	init(t, a, 1, 1, n);
	while(q--) {
		int x, y; cin >> x >> y;
		cout << sum(t, 1, x, y, 1, n) << '\n';
	}
}