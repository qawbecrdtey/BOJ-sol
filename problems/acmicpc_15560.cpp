#include <iostream>
using std::cin;
using std::cout;
using ll = long long;
struct str { ll sum, lsum, rsum, max; };
inline ll mx(ll a, ll b) { return a > b ? a : b; }
void write(str *t, int tidx) {
	t[tidx].sum = t[tidx * 2].sum + t[tidx * 2 + 1].sum;
	t[tidx].lsum = mx(t[tidx * 2].lsum, t[tidx * 2].sum + t[tidx * 2 + 1].lsum);
	t[tidx].rsum = mx(t[tidx * 2 + 1].rsum, t[tidx * 2 + 1].sum + t[tidx * 2].rsum);
	t[tidx].max = mx(mx(t[tidx * 2].max, t[tidx * 2 + 1].max), t[tidx * 2].rsum + t[tidx * 2 + 1].lsum);
}
void init(str *t, ll const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx].sum = t[tidx].lsum = t[tidx].rsum = t[tidx].max = a[l];
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	write(t, tidx);
}
void update(str *t, int tidx, ll idx, ll val, int l, int r) {
	if(idx < l || idx > r) return;
	if(l == r) {
		t[tidx].sum = t[tidx].lsum = t[tidx].rsum = t[tidx].max = val;
		return;
	}
	auto const m = (l + r) / 2;
	update(t, tidx * 2, idx, val, l, m);
	update(t, tidx * 2 + 1, idx, val, m + 1, r);
	write(t, tidx);
}
str max(str const *t, int tidx, ll start, ll end, int l, int r) {
	if(end < l || r < start) return { -100000000, -100000000, -100000000, -100000000 };
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = max(t, tidx * 2, start, end, l, m);
	auto const y = max(t, tidx * 2 + 1, start, end, m + 1, r);
	auto const sum = x.sum + y.sum;
	auto const lsum = mx(x.lsum, x.sum + y.lsum);
	auto const rsum = mx(y.rsum, y.sum + x.rsum);
	auto const maxx = mx(mx(x.max, y.max), x.rsum + y.lsum);
	return { sum, lsum, rsum, maxx };
}
int main() {
	int n; ll q, u, v;
	cin >> n >> q >> u >> v;
	auto a = new ll[n + 1];
	auto t = (str*)malloc((sizeof(str) << 2) * n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = u * a[i] + v;
	}
	init(t, a, 1, 1, n);
	delete[] a;
	while(q--) {
		ll x, y, z;
		cin >> x >> y >> z;
		if(x) {
			update(t, 1, y, u * z + v, 1, n);
		}
		else {
			cout << max(t, 1, y, z, 1, n).max - v << '\n';
		}
	}
	free(t);
}