#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long double r, s; while(cin >> r >> s) {
		assert(s <= 1);
		cout << static_cast<long long>(roundl(sqrtl((r * (s + 0.16L)) / 0.067))) << endl;
	}
}