#include <stdio.h>
using ll = long long;
ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main() {
	ll a[5];
	for(auto &i : a) scanf("%lld", &i);
	ll x = a[0] * a[1] * a[2] * a[3] * a[4];
	for(int i = 0; i < 5; i++) {
		for(int j = i + 1; j < 5; j++) {
			for(int k = j + 1; k < 5; k++) {
				auto const y = lcm(lcm(a[i], a[j]), a[k]);
				if(x > y) x = y;
			}
		}
	}
	printf("%lld", x);
}