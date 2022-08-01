#include <iostream>
using namespace std;
using ll = long long;
inline ll f(ll n) {
	for(ll i = 2; i * i <= n; i++) {
		if(n % i == 0) return i;
	} return n;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	cout << n - n / f(n);
}