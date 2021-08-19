#include <stdio.h>
int main() {
	int n, x;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		int cur = 0;
		while(n--) {
			scanf("%d", &x);
			if(cur != x) {
				printf("%d ", cur = x);
			}
		}
		printf("$\n");
	}
}