#include <cstdio>
#include <vector>
using ll = long long;
inline std::vector<ll> get_fib() {
	std::vector<ll> fib{0, 1};
	while(true) {
		ll const x = fib[fib.size() - 2] + fib[fib.size() - 1];
		if(x > 1000000000000000) return fib;
		fib.push_back(x);
	}
}
inline ll largest_fib(std::vector<ll> const &fib, ll n) {
	ll l = 0, r = fib.size(), res = 0;
	while(l < r) {
		ll const m = (l + r) >> 1;
		if(fib[m] <= n) {
			res = m;
			l = m + 1;
		}
		else r = m;
	} return fib[res];
}
int main() {
	ll n; scanf("%lld", &n);
	auto const fib = get_fib();
	while(n) {
		ll const x = largest_fib(fib, n);
		if(n == x) {
			printf("%lld", x);
			return 0;
		} n -= x;
	}
}