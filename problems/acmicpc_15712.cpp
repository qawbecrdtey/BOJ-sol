#include <iostream>
using namespace std;
using ll = long long;
ll power(ll a, ll n, ll mod) {
	if(!n) return 1;
	if(n == 1) return a;
	ll const r = power(a, n >> 1, mod);
	return (((r * r) % mod) * power(a, n & 1, mod)) % mod;
}
ll sum(ll a, ll r, ll n, ll mod) {
	if(!n) return 0;
	if(n & 1) return a + sum((a * r) % mod, r, n - 1, mod);
	ll const val = sum(a, r, n >> 1, mod);
	ll const x = (1 + power(r, n >> 1, mod));
	return (val * x) % mod;
}
int main() {
	ll a, r, n, mod; cin >> a >> r >> n >> mod;
	cout << sum(a % mod, r % mod, n, mod);
}