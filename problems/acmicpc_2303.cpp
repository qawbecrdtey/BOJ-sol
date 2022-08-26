#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto res = new int[n];
	for(int i = 0; i < n; i++) {
		int a[5]; for(int &j: a) cin >> j;
		int r = 0;
		for(int j = 2; j < 5; j++) {
			for(int k = 1; k < j; k++) {
				for(int l = 0; l < k; l++) {
					r = max(r, (a[j] + a[k] + a[l]) % 10);
				}
			}
		}
		res[i] = r;
	} int ans = 0;
	for(int i = 1; i < n; i++) {
		if(res[i] >= res[ans]) ans = i;
	} cout << ans + 1;
}