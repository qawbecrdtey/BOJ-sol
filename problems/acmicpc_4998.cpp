#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long double a, b, c; while(cin >> a >> b >> c) {
		int cnt = 0;
		while(a < c) {
			a *= 1 + b / 100;
			cnt++;
		} cout << cnt << '\n'; cout << flush;
	}
}