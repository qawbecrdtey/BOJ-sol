#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
inline ll calc(pair<ll, pair<ll, ll>> const &p, ll n) {
	return ((p.first * p.second.first) % M + (p.second.second * n) % M) % M;
}
void init(pair<ll, pair<ll, ll>> *t, ll const *a, ll tidx, ll l, ll r) {
	t[tidx].second.first = 1;
	t[tidx].second.second = 0;
	if(l == r) {
		t[tidx].first = a[l];
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx].first = (t[tidx * 2].first + t[tidx * 2 + 1].first) % M;
}
void update_add(pair<ll, pair<ll, ll>> *t, ll tidx, ll start, ll end, ll val, ll l, ll r) {
	if(end < l || r < start) return;
	if(start <= l && r <= end) {
		t[tidx].second.second = (t[tidx].second.second + val) % M;
		return;
	}
	auto const m = (l + r) / 2;
	if(t[tidx].second.first != 1 || t[tidx].second.second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx * 2].second.first = (t[tidx * 2].second.first * t[tidx].second.first) % M;
		t[tidx * 2].second.second = (((t[tidx * 2].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx * 2 + 1].second.first = (t[tidx * 2 + 1].second.first * t[tidx].second.first) % M;
		t[tidx * 2 + 1].second.second = (((t[tidx * 2 + 1].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx].second.first = 1;
		t[tidx].second.second = 0;
	}
	update_add(t, tidx * 2, start, end, val, l, m);
	update_add(t, tidx * 2 + 1, start, end, val, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].first = (x + y) % M;
}
void update_mul(pair<ll, pair<ll, ll>> *t, ll tidx, ll start, ll end, ll val, ll l, ll r) {
	if(end < l || r < start) return;
	if(start <= l && r <= end) {
		t[tidx].second.first = (t[tidx].second.first * val) % M;
		t[tidx].second.second = (t[tidx].second.second * val) % M;
		return;
	}
	auto const m = (l + r) / 2;
	if(t[tidx].second.first != 1 || t[tidx].second.second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx * 2].second.first = (t[tidx * 2].second.first * t[tidx].second.first) % M;
		t[tidx * 2].second.second = (((t[tidx * 2].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx * 2 + 1].second.first = (t[tidx * 2 + 1].second.first * t[tidx].second.first) % M;
		t[tidx * 2 + 1].second.second = (((t[tidx * 2 + 1].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx].second.first = 1;
		t[tidx].second.second = 0;
	}
	update_mul(t, tidx * 2, start, end, val, l, m);
	update_mul(t, tidx * 2 + 1, start, end, val, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].first = (x + y) % M;
}
void update_val(pair<ll, pair<ll, ll>> *t, ll tidx, ll start, ll end, ll val, ll l, ll r) {
	if(end < l || r < start) return;
	if(start <= l && r <= end) {
		t[tidx].second.first = 0;
		t[tidx].second.second = val;
		return;
	}
	auto const m = (l + r) / 2;
	if(t[tidx].second.first != 1 || t[tidx].second.second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx * 2].second.first = (t[tidx * 2].second.first * t[tidx].second.first) % M;
		t[tidx * 2].second.second = (((t[tidx * 2].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx * 2 + 1].second.first = (t[tidx * 2 + 1].second.first * t[tidx].second.first) % M;
		t[tidx * 2 + 1].second.second = (((t[tidx * 2 + 1].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx].second.first = 1;
		t[tidx].second.second = 0;
	}
	update_val(t, tidx * 2, start, end, val, l, m);
	update_val(t, tidx * 2 + 1, start, end, val, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].first = (x + y) % M;
}
ll sum(pair<ll, pair<ll, ll>> *t, ll tidx, ll start, ll end, ll l, ll r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return calc(t[tidx], r - l + 1);
	auto const m = (l + r) / 2;
	if(t[tidx].second.first != 1 || t[tidx].second.second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx * 2].second.first = (t[tidx * 2].second.first * t[tidx].second.first) % M;
		t[tidx * 2].second.second = (((t[tidx * 2].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx * 2 + 1].second.first = (t[tidx * 2 + 1].second.first * t[tidx].second.first) % M;
		t[tidx * 2 + 1].second.second = (((t[tidx * 2 + 1].second.second * t[tidx].second.first) % M) + t[tidx].second.second) % M;
		t[tidx].second.first = 1;
		t[tidx].second.second = 0;
	}
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return (x + y) % M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new ll[n + 1];
	auto t = new pair<ll, pair<ll, ll>>[n * 4];
	for(int i = 1; i <= n; i++) cin >> a[i];
	init(t, a, 1, 1, n);
	delete[] a;
	cin >> m;
	while(m--) {
		ll w, x, y;
		cin >> w >> x >> y;
		if(w == 4) {
			cout << sum(t, 1, x, y, 1, n) % M << '\n';
			continue;
		}
		ll z; cin >> z;
		if(w == 1) {
			update_add(t, 1, x, y, z, 1, n);
		}
		else if(w == 2) {
			update_mul(t, 1, x, y, z, 1, n);
		}
		else {
			update_val(t, 1, x, y, z, 1, n);
		}
	}
}