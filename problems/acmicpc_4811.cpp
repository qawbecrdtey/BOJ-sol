#include <stdio.h>
using ll = long long;
int main() {
	ll a[31][31] = {};
	for(int i = 0; i <= 30; i++) a[0][i] = 1;
	for(int i = 1; i <= 30; i++) { // one
		for(int j = 0; j < 30; j++) { // half
			a[i][j] = a[i - 1][j + 1];
		}
		for(int j = 1; j <= 30; j++) {
			a[i][j] += a[i][j - 1];
		}
	}
	while(true) {
		int n;
		scanf("%d", &n);
		if(!n) return 0;
		printf("%lld\n", a[n][0]);
	}
}