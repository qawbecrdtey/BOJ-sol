#include <stdio.h>
int f(int x) {
	int res = 0;
	while(x) {
		auto const v = x % 10;
		if(v == 3 || v == 6 || v == 9) res++;
		x /= 10;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= n; i++) {
		res += f(i);
	}
	printf("%d", res);
}