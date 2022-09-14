#include <iostream>
using namespace std;
using ll = long long;
inline constexpr ll M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, x; cin >> n >> x;
	ll res = 0;
	for(int i = 0; i <= n; i++) {
		int a, b; cin >> a >> b;
		res = ((res * x) % M + a) % M;
	} cout << res;
}