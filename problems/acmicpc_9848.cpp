#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k, x, y, r = 0; cin >> n >> k >> x;
	while(--n) {
		cin >> y;
		r += (x - y >= k);
		x = y;
	} cout << r;
}