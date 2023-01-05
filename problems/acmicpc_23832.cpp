#include <iostream>
using namespace std;
using ll = long long;
inline ll phi(ll n) {
	ll res = n;
	for(ll i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			res /= i; res *= i - 1;
		}
	}
	if(n != 1) {
		res /= n; res *= n - 1;
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll res = 0; ll n; cin >> n;
	for(ll i = 2; i <= n; i++) res += phi(i);
	cout << res;
}