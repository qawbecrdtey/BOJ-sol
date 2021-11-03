#include <stdio.h>
int main() {
	int n;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		int cnt = 0;
		for(int a = 1; a * a <= n; a++) {
			for(int b = 0; b <= a && a * a + b * b <= n; b++) {
				for(int c = 0; c <= b && a * a + b * b + c * c <= n; c++) {
					for(int d = 0; d <= c && a * a + b * b + c * c + d * d <= n; d++) {
						cnt += (a * a + b * b + c * c + d * d == n);
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}