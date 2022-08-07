#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
inline ll sum(ll a, ll d, ll l, ll r) {
	return r * (2 * a + (r - 1) * d) / 2 - (l - 1) * (2 * a + (l - 2) * d) / 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, d, q; cin >> a >> d >> q;
	int const g = gcd(a, d);
	while(q--) {
		int x, y, z; cin >> x >> y >> z;
		if(x == 1) cout << sum(a, d, y, z) << '\n';
		else {
			if(y == z) cout << a + ((ll)y - 1) * d << '\n';
			else cout << g << '\n';
		}
	}
}