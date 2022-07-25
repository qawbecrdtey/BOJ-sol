#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case " << tt << ": ";
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		int arr[]{abs(b - d), abs(c - e)};
		if(arr[0] > arr[1]) swap(arr[0], arr[1]);
		if(arr[0] != 1 || arr[1] != 2) cout << "NO\n";
		else cout << "YES\n";
	}
}