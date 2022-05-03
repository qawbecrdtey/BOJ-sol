#include <algorithm>
#include <iostream>
using namespace std;
struct info { int sum, max, lmax, rmax; };
void init(info *t, int const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx].sum = t[tidx].max = t[tidx].lmax = t[tidx].rmax = a[l];
		return;
	}
	auto const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m);
	init(t, a, (tidx << 1) | 1, m + 1, r);
	t[tidx].sum = t[tidx << 1].sum + t[(tidx << 1) | 1].sum;
	t[tidx].max = max({ t[tidx << 1].max, t[(tidx << 1) | 1].max, t[tidx << 1].rmax + t[(tidx << 1) | 1].lmax });
	t[tidx].lmax = max(t[tidx << 1].lmax, t[tidx << 1].sum + t[(tidx << 1) | 1].lmax);
	t[tidx].rmax = max(t[(tidx << 1) | 1].rmax, t[(tidx << 1) | 1].sum + t[tidx << 1].rmax);
}
info val(info const *t, int tidx, int start, int end, int l, int r) {
	if(r < start || end < l) return { 0, -1000000000, -1000000000, -1000000000 };
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) >> 1;
	auto const x = val(t, tidx << 1, start, end, l, m);
	auto const y = val(t, (tidx << 1) | 1, start, end, m + 1, r);
	return { x.sum + y.sum,
			 max({ x.max, y.max, x.rmax + y.lmax }),
			 max(x.lmax, x.sum + y.lmax),
			 max(y.rmax, y.sum + x.rmax)
	};
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	auto t = new info[n << 2];
	init(t, a, 1, 1, n);
	int m; cin >> m;
	while(m--) {
		int x, y; cin >> x >> y;
		cout << val(t, 1, x, y, 1, n).max << '\n';
	}
}