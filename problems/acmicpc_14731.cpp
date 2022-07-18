#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll power(ll n) {
	if(!n) return 1;
	if(n == 1) return 2;
	ll const r = power(n >> 1);
	return (((r * r) % M) * power(n & 1)) % M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll res = 0;
	int n; cin >> n; while(n--) {
		ll a, b; cin >> a >> b; if(!b) continue;
		res = (res + (((power(b - 1) * a) % M) * b) % M) % M;
	} cout << res;
}