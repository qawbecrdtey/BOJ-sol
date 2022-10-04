#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int w, n, p, x, r{}; cin >> w >> n >> p;
	for(int i = 0; i < p; i++) {
		cin >> x; r += (x >= w && x <= n);
	} cout << r;
}