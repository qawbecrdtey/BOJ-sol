#include <stdio.h>
using ll = long long;
ll f(ll n) {
	if(!n) return 0;
	return f(n >> 1) * 3 + (n & 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", f(n));
	}
}