#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int m; cin >> m;
	while(m--) {
		int k, l, r; cin >> k >> l >> r;
		switch(k) {
			case 1: for(int i = l; i <= r; i++) {
				a[i] = a[i] * a[i] % 2010;
			} break;
			case 2: {
				int res = 0;
				for(int i = l; i <= r; i++) {
					res += a[i];
				} cout << res << '\n';
			} break;
			default: __builtin_unreachable();
		}
	}
}