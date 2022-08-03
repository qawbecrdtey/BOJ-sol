#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = n - 1; i; i--) {
		auto p = max_element(a, a + i + 1);
		if(p != a + i) {
			if(!--k) {
				cout << min(*p, a[i]) << ' ' << max(*p, a[i]);
				return 0;
			}
			swap(*p, a[i]);
		}
	} cout << -1;
}