#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t{}, l, p, v; while(cin >> l >> p >> v) {
		if(!l && !p && !v) return 0;
		cout << "Case " << ++t << ": " << v / p * l + min(l, v % p) << '\n';
	}
}