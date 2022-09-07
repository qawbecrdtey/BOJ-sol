#include <iostream>
using namespace std;
using ll = long long;
inline ll dist(ll a, ll b, ll c, ll d) {
	return abs(a - c) + abs(b - d);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	ll sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	int res = 0; ll resval = 0;
	for(int i = 1; i <= n; i++) {
		int m; cin >> m;
		ll nowx = sx, nowy = sy;
		ll d = 0;
		for(int j = 0; j < m; j++) {
			ll x, y; cin >> x >> y;
			d += dist(nowx, nowy, x, y);
			nowx = x, nowy = y;
		} d += dist(nowx, nowy, ex, ey);
		if(!res || d < resval) resval = d, res = i;
	} cout << res;
}