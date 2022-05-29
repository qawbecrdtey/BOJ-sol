#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, m; cin >> n >> m;
	for(ll i = m; i; i--) {
		ll x; cin >> x;
		if(n & 1) cout << x * n << ' ';
		else cout << x * (n + (((ll)1) << i) - 2) << ' ';
		n = ((n + 1) >> 1);
	}
}