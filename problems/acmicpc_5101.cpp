#include <algorithm>
#include <stdio.h>
int main() {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) != EOF) {
		if(a == 0 && b == 0 && c == 0) return 0;
		if(abs(c - a) % abs(b) || (c - a) / b < 0) {
			printf("X\n");
			continue;
		}
		printf("%d\n", (c - a) / b + 1);
	}
}