#include <cstdio>
using ll = long long;
inline bool f(ll n) {
	while(n) {
		if(n % 3 == 2) return false;
		n /= 3;
	} return true;
}
inline bool g(ll n) {
	while(n) {
		if(n % 3 != 1) return false;
		n /= 3;
	} return true;
}
int main() {
	ll a, b; scanf("%lld%lld", &a, &b);
	printf("%d", f(a) && f(b) && g(a + b));
}