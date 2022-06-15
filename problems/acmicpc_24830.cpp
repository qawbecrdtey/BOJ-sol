#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	ll res = 1;
	while(t--) {
		ll a, b; char c[2]; cin >> a >> c >> b;
		switch(*c) {
			case '+': cout << (res = a + b - res) << '\n'; break;
			case '-': cout << (res = (a - b) * res) << '\n'; break;
			case '*': cout << (res = a * a * b * b) << '\n'; break;
			case '/': cout << (res = (a + 1) / 2) << '\n'; break;
			default: __builtin_unreachable();
		}
	}
}