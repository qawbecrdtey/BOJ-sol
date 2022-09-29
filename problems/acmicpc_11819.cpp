#include <iostream>
using namespace std;
using ll = long long;
inline ll power(__int128_t a, __int128_t b, __int128_t c) {
	__int128_t r = 1;
	while(b) {
		if(b & 1) r = (r * a) % c;
		b >>= 1; a = (a * a) % c;
	} return (ll)r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, c; cin >> a >> b >> c; a %= c;
	cout << power(a, b, c);
}