#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t; cin >> t; while(t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		cout << (a * b > c * d ? "TelecomParisTech\n" : (a * b == c * d ? "Tie\n" : "Eurecom\n"));
	}
}