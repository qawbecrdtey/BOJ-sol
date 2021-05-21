#include <stdio.h>
#include <utility>
using namespace std;
using ll = long long;
pair<ll, ll> init(pair<ll, ll> *t, ll const *a, ll i, ll left, ll right) {
	if(left == right) return t[i] = make_pair(a[left], a[left]);
	auto const m = (left + right) / 2;
	auto const l = init(t, a, i * 2, left, m);
	auto const r = init(t, a, i * 2 + 1, m + 1, right);
	return t[i] = make_pair((l.first < r.first ? l.first : r.first), (l.second > r.second ? l.second : r.second));
}
pair<ll, ll> find(pair<ll, ll> *t, ll *a, ll piv, ll start, ll end, ll left, ll right) {
	if(start > right || end < left) return make_pair(1000000001, 0);
	if(start <= left && right <= end) return t[piv];
	auto const m = (left + right) / 2;
	auto const l = find(t, a, piv * 2, start, end, left, m);
	auto const r = find(t, a, piv * 2 + 1, start, end, m + 1, right);
	return make_pair((l.first < r.first ? l.first : r.first), (l.second > r.second ? l.second : r.second));
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new ll[n + 1];
	auto t = new pair<ll, ll>[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	for(int i = 0; i < m; i++) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		auto const res = find(t, a, 1, l, r, 1, n);
		printf("%lld %lld\n", res.first, res.second);
	}
}