#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, q; cin >> n >> m >> q;
	int l = 1, r = 1 + m - 1;
	int res = 0;
	while(q--) {
		int x; cin >> x;
		if(l <= x && x <= r) continue;
		if(x > r) {
			int d = x - r;
			l += d; r += d;
			res += d;
			continue;
		}
		int d = l - x;
		l -= d; r -= d;
		res += d;
	} cout << res;
}