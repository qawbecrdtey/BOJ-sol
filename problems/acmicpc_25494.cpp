#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a, b, c, cnt{}; cin >> a >> b >> c;
		for(int x = 1; x <= a; x++) {
			for(int y = 1; y <= b; y++) {
				for(int z = 1; z <= c; z++) {
					int const xy = (x % y);
					int const yz = (y % z);
					int const zx = (z % x);
					cnt += (xy == yz) && (yz == zx) && (zx == xy);
				}
			}
		}
		cout << cnt << '\n';
	}
}