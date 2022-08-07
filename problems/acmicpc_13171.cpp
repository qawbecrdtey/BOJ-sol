#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll b) {
	if(!b) return 1;
	if(b == 1) return a % M;
	ll r = power(a, b >> 1);
	return (((r * r) % M) * power(a, b & 1)) % M;
}
int main() {
	ll a, b; cin >> a >> b;
	cout << power(a % M, b);
}