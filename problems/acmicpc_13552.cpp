#include <iostream>
using namespace std;
using ll = long long;
struct point{ ll x, y, z; };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new point[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	} int m; cin >> m; while(m--) {
		ll x, y, z, w; cin >> x >> y >> z >> w;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			cnt += ((x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y) + (z - a[i].z) * (z - a[i].z) <= w * w);
		} cout << cnt << '\n';
	}
}