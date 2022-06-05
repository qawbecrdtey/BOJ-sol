#include <iostream>
using namespace std;
using ll = long long;
void init(ll *t, ll const *a, ll tidx, ll l, ll r) {
	if(l == r) {
		t[tidx] = a[l];
		return;
	}
	auto const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m);
	init(t, a, (tidx << 1) | 1, m + 1, r);
	t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
void update(ll *t, ll tidx, ll idx, ll val, ll l, ll r) {
	if(idx < l || idx > r) return;
	if(l == r) {
		t[tidx] = val;
		return;
	}
	auto const m = (l + r) >> 1;
	update(t, tidx << 1, idx, val, l, m);
	update(t, (tidx << 1) | 1, idx, val, m + 1, r);
	t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
ll sum(ll const *t, ll tidx, ll start, ll end, ll l, ll r) {
	if(end < l || r < start) return 0;
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
	auto arr = new ll[n + 1]; arr[0] = 0;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	auto t = new ll[n << 2];
	init(t, arr, 1, 1, n);
	while(q--) {
		ll x, a, b; cin >> x >> a >> b;
		ll const v1 = sum(t, 1, a, b, 1, n);
		if(x == 1) {
			cout << v1 << '\n';
			ll const va = arr[a], vb = arr[b];
			swap(arr[a], arr[b]);
			update(t, 1, a, vb, 1, n);
			update(t, 1, b, va, 1, n);
		}
		else {
			ll c, d; cin >> c >> d;
			cout << v1 - sum(t, 1, c, d, 1, n) << '\n';
		}
	}
}