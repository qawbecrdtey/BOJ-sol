#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, d; cin >> n >> d;
	map<ll, ll> m;
	for(int i = 0; i < n; i++) {
		ll x; cin >> x; m[x / d]++;
	} ll res = 0;
	for(auto it = m.begin(); it != m.end(); ++it) {
		res += it->second * (it->second - 1) / 2;
	} cout << res;
}