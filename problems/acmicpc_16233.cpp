#include <stdio.h>
inline int sum(int n) {
	int res = 0;
	while(n) {
		res += n % 10;
		n /= 10;
	} return res;
}
int main() {
	int t, n;
	scanf("%d", &t);
OK:	while(t--) {
		scanf("%d", &n);
		for(int i = (10 - (n % 10)) % 10; i <= 81; i += 10) {
			if (sum(n + i) == i) {
				printf("%d ", n + i);
				goto OK;
			}
		} printf("-1 ");
	}
}