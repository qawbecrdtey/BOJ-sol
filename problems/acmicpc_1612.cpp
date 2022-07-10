#include <cstdio>
using ll = long long;
int main() {
	ll n; scanf("%lld", &n);
	if(n % 5 == 0 || n % 2 == 0) {
		printf("-1");
		return 0;
	}
	if(n == 1) {
		printf("1");
		return 0;
	}
	ll cnt = 1, mul = 10, val = 1;
	do {
		val = (val + mul) % n;
		mul = (mul * 10) % n;
		cnt++;
	} while(val != 0);
	printf("%lld", cnt);
}