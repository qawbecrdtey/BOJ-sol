#include <iostream>
using namespace std;
constexpr uint64_t M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	uint32_t a[32]{};
	for(int i = 0; i < n; i++) {
		uint32_t x; cin >> x;
		for(int j = 0; j < 32; j++) {
			a[j] += ((x >> j) & 1);
		}
	}
	uint64_t res = 1;
	for(int i = 0; i < n; i++) {
		uint64_t x = 0;
		for(int j = 0; j < 32; j++) {
			if(a[j]) {
				x |= (1 << j);
				a[j]--;
			}
		}
		res = (res * x) % M;
	} cout << res;
}