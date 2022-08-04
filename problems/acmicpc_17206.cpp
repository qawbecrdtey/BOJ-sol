#include <iostream>
using namespace std;
using ll = long long;
inline ll sum(ll n) { return n * (n + 1) / 2; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		cout << sum(n / 3) * 3 + sum(n / 7) * 7 - sum(n / 21) * 21 << '\n';
	}
}