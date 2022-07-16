#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	int res = n / 100 * 100 + 99;
	if(n / 100 != 0) {
		int x = (n / 100 - 1) * 100 + 99;
		if(n - x < res - n) res = x;
	} printf("%d", res);
}