#include <iostream>
using namespace std;
inline bool found(int x, int k) {
	return x % 10 == k || x / 10 == k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	int cnt = 0;
	for(int h = 0; h <= n; h++) {
		for(int m = 0; m < 60; m++) {
			for(int s = 0; s < 60; s++) {
				cnt += found(h, k) || found(m, k) || found(s, k);
			}
		}
	} cout << cnt;
}