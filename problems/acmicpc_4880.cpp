#include <stdio.h>
int main() {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) != EOF) {
		if(a == 0 & b == 0 && c == 0) return 0;
		if(c - b == b - a) printf("AP %d\n", (c << 1) - b);
		else printf("GP %d\n", c * c / b);
	}
}