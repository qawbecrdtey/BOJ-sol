#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
	ll n; cin >> n;
	auto a = new ll[n]; a[0] = 1;
	for(ll i = 1; i < n - 1; i++) {
		cin >> a[i];
		a[0] = lcm(a[0], a[i]);
	} cout << a[0];
}