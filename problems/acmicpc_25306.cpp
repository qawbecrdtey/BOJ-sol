#include <cstdio>
using ll = long long;
ll calc(ll n) {
	switch (n & 3) {
		case 0: return n;
		case 1: return n ^ (n - 1);
		case 2: return n + 1;
		case 3: return 0;
		default: __builtin_unreachable();
	}
}
int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", calc(a - 1) ^ calc(b));
}