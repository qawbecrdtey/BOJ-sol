#include <iostream>
using namespace std;
using ll = long long;
inline ll score(ll a, ll b, ll c) {
	ll r = a * (b + c);
	if(a == b + c) r <<= 1;
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; ll m{}; while(t--) {
		int a, b, c; cin >> a >> b >> c;
		m = max(m, score(a, b, c));
	} cout << m;
}