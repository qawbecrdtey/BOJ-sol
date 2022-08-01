#include <cstdio>
using ll = unsigned long long;
int main() {
	ll n; scanf("%llu", &n);
	if(!n) {
		printf("NO");
		return 0;
	}
	while(n) {
		if(n % 3 == 2) {
			printf("NO");
			return 0;
		}
		n /= 3;
	} printf("YES");
}