#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int cur = 2, ans = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x == (cur + 1) % 3) ans++, cur = (cur + 1) % 3;
	} cout << ans;
}