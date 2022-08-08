#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		int res = 1; while(!(n & 1)) n >>= 1;
		for(int i = 3; i * i <= n; i += 2) {
			int s = 1;
			while(!(n % i)) {
				n /= i;
				s++;
			} res *= s;
		}
		if(n != 1) {
			res *= 2;
		} cout << res - 1 << '\n';
	}
}