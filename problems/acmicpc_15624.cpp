#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if(!n) {
		printf("0");
		return 0;
	}
	int a = 0, b = 1;
	for(int i = 1; i < n; i++) {
		int tmp = b;
		b = (a + b) % 1000000007;
		a = tmp;
	}
	printf("%d", b);
}