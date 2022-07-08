#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto val = new int[n];
	for(int i = 0; i < n; i++) {
		int p, l; cin >> p >> l;
		auto a = new int[p];
		for(int j = 0; j < p; j++) cin >> a[j];
		if(p >= l) {
			sort(a, a + p);
			val[i] = a[p - l];
		} else val[i] = 1;
		delete[] a;
	}
	sort(val, val + n);
	int cnt = 0;
	while(cnt < n) {
		if(m < val[cnt]) break;
		m -= val[cnt++];
	}
	cout << cnt;
}