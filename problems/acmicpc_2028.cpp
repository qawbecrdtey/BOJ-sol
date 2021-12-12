#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int val = 1;
		while(val <= n) val *= 10;
		if((n * n) % val == n) printf("YES\n");
		else printf("NO\n");
	}
}