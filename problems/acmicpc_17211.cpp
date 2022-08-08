#include <iostream>
using namespace std;
using ld = long double;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto a = new ld[4];
	for(int i = 0; i < 4; i++) cin >> a[i];
	ld res[2]{ld(1 - k), ld(k)};
	while(n--) {
		ld b[2]; copy(res, res + 2, b);
		res[0] = b[0] * a[0] + b[1] * a[2];
		res[1] = b[0] * a[1] + b[1] * a[3];
	} cout.precision(0);
	cout << fixed << res[0] * 1000 << '\n' << res[1] * 1000;
}