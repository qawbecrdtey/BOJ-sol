#include <stdio.h>
using ll = long long;
ll cube(ll a) { return a * a * a; }
int main() {
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; t++) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		int cnt = 0;
		for(ll i = 0; cube(i) <= b; i++) {
			cnt += (cube(i) >= a);
		}
		printf("Case #%d: %d\n", t, cnt);
	}
}