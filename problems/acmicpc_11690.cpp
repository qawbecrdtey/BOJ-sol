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
int main() {
	ll n; scanf("%lld", &n);
	auto const primes = get_primes(n);
	ll res = 1;
	for(ll p : primes) {
		ll x = 1;
		while(x * p <= n) x *= p;
		res = (res * x) % (1LL << 32);
	} printf("%lld", res);
}