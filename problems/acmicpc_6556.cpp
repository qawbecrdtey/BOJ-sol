#include <iostream>
using namespace std;
using ll = long long;
inline ll c(ll n, ll k) {
	ll x = 1;
	for(ll i = 1; i <= k; i++) {
		x *= n - i + 1;
		x /= i;
	} return x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a, b; while(cin >> a >> b) {
		if(!a && !b) return 0;
		cout << c(a + b, min(a, b)) << '\n';
	}
}