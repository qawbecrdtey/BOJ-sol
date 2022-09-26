#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int m = 1 << 30;
	int res = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(m < x) res = max(res, x - m);
		m = min(m, x);
	} cout << res;
}