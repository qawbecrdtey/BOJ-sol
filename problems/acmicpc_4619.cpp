#include <stdio.h>
int power(int x, int n) {
	int res = 1;
	for(int i = 0; i < n; i++) res *= x;
	return res;
}
int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF) {
		if(a == 0 && b == 0) return 0;
		int prev = 1, now, i;
		for(i = 2; (now = power(i, b)) < a; i++) prev = now;
		int res = now - a, resi = i;
		if(a - prev < res) res = a - prev, resi = i - 1;
		printf("%d\n", resi);
	}
}