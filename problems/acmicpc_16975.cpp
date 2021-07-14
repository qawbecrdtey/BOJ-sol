#include <stdio.h>
#include <utility>
using namespace std;
using ll = long long;
ll init(pair<ll, ll> *t, ll const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx] = make_pair(a[l], 0);
		return a[l];
	}
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx] = make_pair(x + y, 0);
	return t[tidx].first;
}
ll update(pair<ll, ll> *t, ll *a, int tidx, int start, int end, ll val, int l, int r) {
	if(r < start || end < l) return t[tidx].first + t[tidx].second * (r - l + 1);
	if(start <= l && r <= end) {
		t[tidx].second += val;
		return t[tidx].first + t[tidx].second * (r - l + 1);
	}
	auto const m = (l + r) / 2;
	if(t[tidx].second) {
		update(t, a, tidx * 2, l, r, t[tidx].second, l, m);
		update(t, a, tidx * 2 + 1, l, r, t[tidx].second, m + 1, r);
		t[tidx].second = 0;
	}
	auto const x = update(t, a, tidx * 2, start, end, val, l, m);
	auto const y = update(t, a, tidx * 2 + 1, start, end, val, m + 1, r);
	return t[tidx].first = x + y;
}
ll val(pair<ll, ll> *t, ll const *a, int tidx, ll idx, int l, int r) {
	if(idx < l || idx > r) return 0;
	if(l == r) {
		t[tidx].first += t[tidx].second;
		t[tidx].second = 0;
		return t[tidx].first;
	}
	auto const m = (l + r) / 2;
	auto const x = val(t, a, tidx * 2, idx, l, m);
	auto const y = val(t, a, tidx * 2 + 1, idx, m + 1, r);
	return x + y + t[tidx].second;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n + 1];
	auto t = new pair<ll, ll>[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	int m;
	scanf("%d", &m);
	while(m--) {
		int w;
		scanf("%d", &w);
		if(w == 1) {
			int x, y; ll z;
			scanf("%d%d%lld", &x, &y, &z);
			update(t, a, 1, x, y, z, 1, n);
		}
		else {
			ll x;
			scanf("%lld", &x);
			printf("%lld\n", val(t, a, 1, x, 1, n));
		}
	}
	delete[] a;
	delete[] t;
}