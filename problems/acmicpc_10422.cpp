#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a[2501]{ 1, 1, 2 };
	for(int i = 3; i <= 2500; i++) {
		for(int l = 0, r = i - 1; l <= r; l++, r--) {
			a[i] = (a[i] + a[l] * a[r] * (1 + (l != r))) % M;
		}
	}
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		if(n & 1) cout <<"0\n";
		else cout << a[n >> 1] << '\n';
	}
}