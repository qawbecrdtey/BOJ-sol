#include <stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int res = 2;
	if(a < b) {
		int c = a; a = b; b = c;
	}
	while(a >= b) {
		res++;
		int c = a - b;
		a = b; b = c;
	}
	printf("%d", res);
}