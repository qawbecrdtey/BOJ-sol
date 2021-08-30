#include <stdio.h>
int main() {
	int n, x, max = 0, maxc = 0, cur = 0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		if(x >= max) {
			max = x;
			cur = 0;
		}
		else cur++;
		if(cur > maxc) maxc = cur;
	}
	printf("%d", maxc);
}