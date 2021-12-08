#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d %d %d %d\n", x, y * (y + 1) / 2, y * y, y * (y + 1));
	}
}