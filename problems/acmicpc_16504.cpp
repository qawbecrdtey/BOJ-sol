#include <stdio.h>
int main() {
	long long n, res = 0, x;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%lld", &x);
			res += x;
		}
	} printf("%lld", res);
}