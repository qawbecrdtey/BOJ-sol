#include <iostream>
using namespace std;
using ll = long long;
ll power(ll a, ll k, ll m) {
	if(!k) return 1;
	if(k == 1) return a % m;
	ll const r = power(a, k >> 1, m);
	return ((r * r) % m * power(a, k & 1, m)) % m;
}
bool is_prime(ll p) {
	for(ll i = 2; i * i <= p; i++) {
		if(p % i) continue;
		return false;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll p, a;
	while(true) {
		cin >> p >> a;
		if(!p && !a) return 0;
		cout << ((!is_prime(p) && power(a, p, p) == a % p) ? "yes\n" : "no\n");
	}
}