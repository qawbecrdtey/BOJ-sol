#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		int a[5]; for(int &i : a) cin >> i;
		cout << *max_element(a, a + 5) << '\n';
	}
}