#pragma GCC optimize "Ofast"
#pragma GCC optimize "associative-math"
#pragma GCC optimize "fast-math"
#pragma GCC optimize "finite-math-only"
#pragma GCC optimize "no-math-errno"
#pragma GCC optimize "no-trapping-math"
#pragma GCC optimize "reciprocal-math"
#pragma GCC optimize "rounding-math"
#pragma GCC optimize "unsafe-math-optimizations"

#include <cstdio>
using ll = long long;
struct str { ll x, y, z, w; };
inline str operator*(str const &a, str const &b) {
	return {
		a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w,
		a.x * b.y - a.y * b.x - a.z * b.w + a.w * b.z,
		a.x * b.z + a.y * b.w - a.z * b.x - a.w * b.y,
		a.x * b.w - a.y * b.z + a.z * b.y - a.w * b.x
	};
}
inline ll sqrt(ll n) {
	ll l = 0, r = n + 1, res = n;
	while(l < r) {
		ll const m = (l + r) / 2;
		if(m * m == n) return m;
		if(m * m < n) res = m, l = m + 1;
		else r = m;
	}
	return res;
}
inline str make_str(ll n) {
	for(ll i = 1; i * i <= n; i++) {
		for(ll j = 0; j <= i && i * i + j * j <= n; j++) {
			for(ll k = 0; k <= j && i * i + j * j + k * k <= n; k++) {
				ll const l = n - i * i - j * j - k * k;
				ll const m = sqrt(l);
				if(m * m == l) return { i, j, k, m };
			}
		}
	}
	__builtin_unreachable();
}
inline ll f(ll n) { if(n < 0) return -n; return n; }
int main() {
	ll n; scanf("%lld", &n);
	ll i = 2;
	auto s = make_str(1);
	while(i * i <= n) {
		auto const t = make_str(i);
		while(n % i == 0) {
			n /= i;
			s = s * t;
		}
		i++;
	}
	if(n != 1) {
		s = s * make_str(n);
	}
	printf("%lld %lld %lld %lld", f(s.x), f(s.y), f(s.z), f(s.w));
}