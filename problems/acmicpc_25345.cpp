#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll n) {
	if(!n) return 1;
	if(n == 1) return a;
	ll const r = power(a, n >> 1);
	return (((r * r) % M) * power(a, n & 1)) % M;
}
inline ll inverse(ll n) { return power(n, M - 2); }
inline ll binom(ll n, ll k) {
	ll res = 1;
	ll inv = 1;
	for(ll i = 1; i <= k; i++) {
		res = (res * (n - i + 1)) % M;
		inv = (inv * i) % M;
	}
	return (res * inverse(inv)) % M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, k; cin >> n >> k;
	cout << (binom(n, k) * power(2, k - 1)) % M;
}