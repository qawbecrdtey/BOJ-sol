#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		if(n < 12 || m < 4) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", 11 * m + 4);
	}
}