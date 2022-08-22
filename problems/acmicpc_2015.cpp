#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, k; cin >> n >> k;
	auto a = new ll[n + 1]; a[0] = 0;
	map<ll, ll> m; m[0] = 1;
	ll res = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i - 1];
		res += m[a[i] - k];
		m[a[i]]++;
	} cout << res;
}