#include <iostream>
using namespace std;
inline int cnt(int n) {
	int res = 0;
	for(int i = 1; i <= n; i++) {
		res += (n % i == 0);
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= n; j++) {
			if(cnt(n * i + j) <= k) cout << '*';
			else cout << '.';
		} cout << '\n';
	}
}