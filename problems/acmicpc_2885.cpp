#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	int res = 1;
	while(res < n) res <<= 1;
	printf("%d ", res);
	int cut = 0, sum = 0;
	while(true) {
		if(sum + res == n) break;
		cut++; res >>= 1;
		if(sum + res < n) sum += res;
	} printf("%d", cut);
}