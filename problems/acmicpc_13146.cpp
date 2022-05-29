#include <iostream>
using namespace std;
using ll = long long;
struct info { int height, num; ll sum; };
void init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) { t[tidx] = l; return; }
	auto const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m);
	init(t, a, (tidx << 1) | 1, m + 1, r);
	t[tidx] = (a[t[tidx << 1]] >= a[t[(tidx << 1) | 1]] ? t[tidx << 1] : t[(tidx << 1) | 1]);
}
int maxi(int const *t, int const *a, int tidx, int start, int end, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) >> 1;
	auto const x = maxi(t, a, tidx << 1, start, end, l, m);
	auto const y = maxi(t, a, (tidx << 1) | 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[x] >= a[y] ? x : y;
}
info calc(int const *t, int const *a, int n, int l, int r) {
	if(l == r) return { a[l], 1, 0 };
	auto const mi = maxi(t, a, 1, l, r, 1, n);
	info left{}, right{};
	if(l != mi) left = calc(t, a, n, l, mi - 1);
	if(r != mi) right = calc(t, a, n, mi + 1, r);
	ll res = left.sum + right.sum;
	if(left.num) res += a[mi] - left.height;
	if(right.num) res += a[mi] - right.height;
	return { a[mi], left.num + right.num + 1, res };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n + 1]; for(int i = 1; i <= n; i++) cin >> a[i];
	auto t = new int[n << 2];
	init(t, a, 1, 1, n);
	auto res = calc(t, a, n, 1, n);
	cout << res.sum;
}