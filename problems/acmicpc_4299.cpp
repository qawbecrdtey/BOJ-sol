#include <stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if((a + b) % 2 || a < b) {
		printf("-1");
		return 0;
	}
	printf("%d %d", (a + b) / 2, (a - b) / 2);
}