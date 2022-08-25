#include <iostream>
using namespace std;
using ll = long long;
inline __int128_t sum(ll a) { return (__int128_t)a * (a + 1) / 2; }
inline int f(__int128_t n) { return (int)(n % 9); }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a, b; cin >> a >> b;
	cout << (f(sum(b)) - f(sum(a - 1)) + 9) % 9;
}