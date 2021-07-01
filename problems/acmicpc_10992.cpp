#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) printf(" ");
		printf("*");
		if(i == 0) {
			printf("\n");
			continue;
		}
		if(i == n - 1) {
			for(int j = 0; j < 2 * n - 2; j++) {
				printf("*");
			}
			break;
		}
		for(int j = 0; j < 2 * i - 1; j++) {
			printf(" ");
		}
		printf("*\n");
	}
}