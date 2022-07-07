#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes(ll n) {
	vector<ll> primes{ 2, 3 };
	vector<bool> visited(n + 1);
	ll i = 5, d = 4;
	for(; i * i <= n; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(ll j = i; j <= n; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i <= n; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	}
	return primes;
}
inline ll sqrt(ll n) {
	ll l = 0, r = (((n + 1) > 10000000) ? 10000000 : (n + 1));
	ll res = 0;
	while(l < r) {
		ll const m = (l + r) >> 1;
		ll const m2 = m * m;
		if(m2 == n) return m;
		if(m2 > n) r = m;
		else res = m, l = m + 1;
	} return res;
}
int main() {
	ll a, b; scanf("%lld%lld", &a, &b);
	auto const primes = get_primes(sqrt(b));
	ll cnt = 0;
	for(ll p : primes) {
		for(__int128_t i = p * p; i <= b; i *= p) {
			cnt += (i >= a);
		}
	} printf("%lld", cnt);
}