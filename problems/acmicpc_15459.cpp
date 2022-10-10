#include <cassert>
#include <iostream>
#include <limits>
using namespace std;
using ll = long long;
void init(ll *t, ll const *a, ll tidx, ll l, ll r) {
	if(l == r) {
		t[tidx] = a[l];
		return;
	}
	ll const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m);
	init(t, a, (tidx << 1) | 1, m + 1, r);
	t[tidx] = max(t[tidx << 1], t[(tidx << 1) | 1]);
}
ll get_max(ll const *t, ll tidx, ll start, ll end, ll l, ll r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return t[tidx];
	ll const m = (l + r) >> 1;
	ll const x = get_max(t, tidx << 1, start, end, l, m);
	ll const y = get_max(t, (tidx << 1) | 1, start, end, m + 1, r);
	return max(x, y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, m; cin >> n >> m;
	auto a = new ll[n + 1];
	auto b = new ll[n + 1];
	for(ll i = 1; i <= n; i++) {
		cin >> b[i] >> a[i];
	}
	auto t = new ll[n << 2];
	init(t, a, 1, 1, n);
	ll l = 1, r = 1, sum = 0;
	ll res = numeric_limits<ll>::max();
	while(l <= n) {
		if(l == r) {
			assert(sum == 0);
			sum += b[r++];
			continue;
		}
		if(sum >= m) {
			res = min(res, get_max(t, 1, l, r - 1, 1, n));
			sum -= b[l++];
			continue;
		}
		if(r == n + 1) {
			sum -= b[l++];
			continue;
		}
		sum += b[r++];
	} cout << res;
}