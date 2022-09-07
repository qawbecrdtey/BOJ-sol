#include <iostream>
using namespace std;
using ll = long long;
inline constexpr ll M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		ll n; cin >> n;
		ll res = 1;
		for(ll i = 1; i <= n; i++) res = (res * i) % M;
		cout << (res + M - 1) % M << '\n';
	}
}