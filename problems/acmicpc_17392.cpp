#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		ll x; cin >> x; m -= x + 1;
	}
	if(m <= 0) {
		cout << 0;
		return 0;
	}
	ll res = 0;
	while(n >= 0) {
		ll const k = m / (n + 1);
		m -= k;
		cout << "k = " << k << '\n';
		res += k * (k + 1) * (2 * k + 1) / 6;
		n--;
	} cout << res;
}