#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x < y) printf("NO BRAINS\n");
		else printf("MMM BRAINS\n");
	}
}