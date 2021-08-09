#include <cassert>
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
	ll a, b;
	cin >> a >> b;
	assert(b % a == 0);
	b /= a;
	ll x, y;
	for(int i = 1; i * i <= b; i++) {
		if(b % i == 0 && gcd(i, b / i) == 1) {
			x = i, y = b / i;
		}
	}
	cout << x * a << ' ' << y * a;
}