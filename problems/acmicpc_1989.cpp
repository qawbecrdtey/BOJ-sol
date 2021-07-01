#include <stdio.h>
#include <utility>
using namespace std;
using ll = long long;
int init(int *t, ll const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] > a[y] ? y : x);
}
int mini(int const *t, ll const *a, int tidx, int start, int end, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[x] > a[y] ? y : x;
}
pair<ll, pair<int, int>> f(int const *t, ll const *a, ll const *sumarr, int n, int l, int r) {
	if(l > r) return make_pair(0, make_pair(0, 0));
	auto piv = mini(t, a, 1, l, r, 1, n);
	auto res = make_pair(a[piv] * (sumarr[r] - sumarr[l - 1]), make_pair(l, r));
	auto const x = f(t, a, sumarr, n, l, piv - 1);
	auto const y = f(t, a, sumarr, n, piv + 1, r);
	if(res < x) res = x;
	if(res < y) res = y;
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n + 1];
	auto sumarr = new ll[n + 1]();
	auto t = new int[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sumarr[i] = sumarr[i - 1] + a[i];
	}
	init(t, a, 1, 1, n);
	auto const res = f(t, a, sumarr, n, 1, n);
	printf("%lld\n%d %d", res.first, res.second.first, res.second.second);
}