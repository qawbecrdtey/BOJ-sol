#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	int res = 1;
	for(int i = 2; i <= n; i++) {
		int now = i;
		for(int j = 2; j <= k; j++) {
			while(now % j == 0) now /= j;
			if(now == 1) break;
		}
		res += (now == 1);
	} cout << res;
}