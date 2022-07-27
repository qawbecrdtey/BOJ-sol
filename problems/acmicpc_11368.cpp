#include <iostream>
using namespace std;
using ll = long long;
ll power(ll a, ll n) {
	if(!n) return 1;
	if(n == 1) return a;
	ll const r = power(a, n >> 1);
	return r * r * power(a, n & 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll c, w, l, p; while(cin >> c >> w >> l >> p) {
		if(!c && !w && !l && !p) return 0;
		cout << power(c, w * l * p) << '\n';
	}
}