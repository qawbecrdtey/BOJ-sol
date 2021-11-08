#include <stdio.h>
using lll = __int128;
using ll = long long;
int main() {
	int n; scanf("%d", &n);
	lll res = 1;
	for(int i = 1; i <= n; i++) {
		int x = i;
		while(x % 5 == 0) {
			res /= 2;
			x /= 5;
		}
		res *= x;
		res %= 10000000000;
	}
	printf("%lld", (ll)(res % 10));
}