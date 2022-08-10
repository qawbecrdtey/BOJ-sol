#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll h, x; cin >> h >> x;
	ll mul = x, sum = 0;
	for(ll i = 1; i <= h; i++) {
		ll n; cin >> n;
		sum = (sum + (mul * n) % M) % M;
		mul = (mul * x) % M;
	} cout << sum;
}