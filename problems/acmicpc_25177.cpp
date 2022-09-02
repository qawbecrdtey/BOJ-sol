#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m; int k = max(n, m);
	auto a = new int[k]();
	for(int i = 0; i < n; i++) {
		cin >> a[i]; a[i] = -a[i];
	}
	for(int i = 0; i < m; i++) {
		int x; cin >> x; a[i] += x;
	} int r = *max_element(a, a + k);
	if(r < 0) cout << 0;
	else cout << r;
}