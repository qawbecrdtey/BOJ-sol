#include <cstdio>
#include <vector>
using ll = long long;
int main() {
	ll a, b;
	std::vector<ll> primes;
	scanf("%lld%lld", &a, &b);
	auto arr = new ll[b + 1]();
	for(ll i = 2; i <= b; i++) {
		if(arr[i]) continue;
		primes.push_back(i);
		ll mul = i;
		while(mul <= b) {
			for(ll j = mul; j <= b; j += mul) arr[j]++;
			mul *= i;
		}
	}
	ll cnt = 0;
	for(ll i = a; i <= b; i++) {
		auto it = std::lower_bound(primes.begin(), primes.end(), arr[i]);
		cnt += (it != primes.end() && *it == arr[i]);
	}
	printf("%lld", cnt);
}