#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = n - 3; i >= 0; i--) {
		if(a[i] + a[i + 1] > a[i + 2]) {
			cout << a[i] + a[i + 1] + a[i + 2];
			return 0;
		}
	} cout << -1;
}