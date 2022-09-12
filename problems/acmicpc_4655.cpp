#include <iostream>
using namespace std;
inline long long f(long double d) {
	long double x = 0; long long cnt = 1;
	while(x < d) {
		x += 1.0L / (++cnt);
	}
	return cnt - 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long double d; while(cin >> d) {
		if(d == 0) return 0;
		cout << f(d) << " card(s)\n";
	}
}