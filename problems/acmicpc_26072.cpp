#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, l; cin >> n >> l;
	auto a = new ll[n];
	ll res{}, sum{};
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		ll x; cin >> x; res += a[i] * x; sum += x;
	} cout.precision(12);
	cout << fixed << (long double)res / sum;
}