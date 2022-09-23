#include <array>
#include <cassert>
#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(3);
	long double a[8];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7]) {
		map<array<long double, 2>, int> m;
		m[{ a[0], a[1] }]++;
		m[{ a[2], a[3] }]++;
		m[{ a[4], a[5] }]++;
		m[{ a[6], a[7] }]++;
		assert(m.size() == 3);
		array<long double, 2> res{};
		for(auto [key, value] : m) {
			// OA + AB + AC = A + (B - A) + (C - A) = B + C - A
			if(value & 1) {
				res[0] += key[0];
				res[1] += key[1];
			}
			else {
				res[0] -= key[0];
				res[1] -= key[1];
			}
		} cout << fixed << res[0] << ' ' << res[1] << '\n';
	}
}