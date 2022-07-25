#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		int a[3]; cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << "Case #" << tt << ": " << ((a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) ? "YES\n" : "NO\n");
	}
}