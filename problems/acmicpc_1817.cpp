#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	if(n == 0) {
		cout << 0;
		return 0;
	}
	int cap = m, cnt = 1;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(cap >= x) cap -= x;
		else {
			cap = m - x; cnt++;
		}
	} cout << cnt;
}