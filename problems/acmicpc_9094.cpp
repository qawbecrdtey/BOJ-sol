#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int m, n;
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for(int a = 1; a < n; a++) {
			for(int b = a + 1; b < n; b++) {
				cnt += ((a * a + b * b + m) % (a * b) == 0);
			}
		}
		printf("%d\n", cnt);
	}
}