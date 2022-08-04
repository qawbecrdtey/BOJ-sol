#include <cstdio>
using ll = long long;
inline ll count_zero(ll n) {
	ll x = 5, res = 0;
	while(x <= n) {
		res += n / x;
		x *= 5;
	} return res;
}
int main() {
	ll n; scanf("%lld", &n);
	ll r = 2; while(count_zero(r) < n) r <<= 1;
	ll l = (r >> 1);
	ll res = r;
	while(l < r) {
		ll const m = ((l + r) >> 1);
		if(count_zero(m) >= n) {
			res = m;
			r = m;
			continue;
		}
		l = m + 1;
	} if(count_zero(res) != n) printf("-1");
	else printf("%lld", res);
}