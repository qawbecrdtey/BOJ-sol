#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline vector<ll> get_primes(ll n) {
	vector<ll> primes{2, 3}; primes.reserve(283146);
	vector<bool> visited(n + 1);
	ll i = 5, d = 4;
	for(; i * i <= n; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(ll j = (i * i); j <= n; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i <= n; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	} return primes;
}
inline ll power(ll a, ll n, ll m) {
	ll res = 1;
	while(n) {
		if(n & 1) res = (res * a) % m;
		a = (a * a) % m; n >>= 1;
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, k, m; cin >> n >> k >> m;
	if(m == 1) { cout << 0; return 0; }
	auto const primes = get_primes(n);
	ll const x = n - k;
	ll res = 1;
	for(ll p : primes) {
		ll j, c = 0;
		for(j = p; j <= n; j *= p) c += n / j;
		for(j = p; j <= k; j *= p) c -= k / j;
		for(j = p; j <= x; j *= p) c -= x / j;
		res = (res * power(p, c, m)) % m;
	} cout << res;
}