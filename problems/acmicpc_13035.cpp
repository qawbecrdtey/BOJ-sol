#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline ll closest(vector<ll> const &v, ll val) {
	assert(!v.empty());
	ll res = abs(val - v.back()), resi = v.size() - 1;
	for(int i = 0; i < v.size() - 1; i++) {
		ll const x = abs(val - v[i]);
		if(res > x && v[i] != 0) {
			res = x, resi = i;
		}
	} return v[resi];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		ll a, b, c; cin >> a >> b >> c;
		cout << closest({a * b / (c * c) * (c * c), (a * b / (c * c) + 1) * (c * c)}, a * b) << '\n';
	}
}