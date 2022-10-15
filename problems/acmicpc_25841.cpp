#include <iostream>
using namespace std;
inline int f(int n, int d) {
	int r{};
	while(n) {
		r += (n % 10 == d);
		n /= 10;
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int x, y, d, r{}; cin >> x >> y >> d;
	for(int i = x; i <= y; i++) {
		r += f(i, d);
	} cout << r;
}