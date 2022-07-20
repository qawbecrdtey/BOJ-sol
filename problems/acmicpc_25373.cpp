#include <iostream>
using namespace std;
using ll = long long;
ll f(ll n) {
	if(n == 1) return 1;
	if(n <= 3) return 2;
	if(n <= 6) return 3;
	if(n <= 10) return 4;
	if(n <= 15) return 5;
	if(n <= 21) return 6;
	if(n <= 28) return 7;
	if(n % 7) return n / 7 + 4;
	return n / 7 + 3;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n; cout << f(n);
}