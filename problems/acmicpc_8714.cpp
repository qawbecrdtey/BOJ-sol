#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; int res = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; res += x;
	} cout << min(res, n - res);
}