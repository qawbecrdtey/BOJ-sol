#include <stdio.h>
using ll = long long;
ll phi(ll n) {
	ll res = n;
	for(int i = 2; i * i <= n; i++) {
		bool flag = false;
		while(n % i == 0) {
			flag = true;
			n /= i;
		}
		if(!flag) continue;
		res = res / i * (i - 1);
	}
	if(n > 1) {
		res = res / n * (n - 1);
	}
	return res;
}
int main() {
	ll n; scanf("%lld", &n);
	ll res = -1;
	for(ll i = 1; i * i <= n; i++) {
		if(n % i) continue;
		if(i * phi(i) == n) {
			printf("%lld", i);
			return 0;
		}
		else if(i * i != n && (n / i) * phi(n / i) == n) {
			res = n / i;
		}
	}
	printf("%lld", res);
}