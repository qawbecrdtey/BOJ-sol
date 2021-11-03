#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, i = 0;
		scanf("%d", &n);
		for(; i <= n; i++) if(i * (i + 1) > n) break;
		printf("%d\n", i - 1);
	}
}