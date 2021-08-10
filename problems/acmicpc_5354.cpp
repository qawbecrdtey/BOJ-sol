#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		if(n == 1) {
			printf("#\n\n");
			continue;
		}
		for(int i = 0; i < n; i++) printf("#");
		printf("\n");
		for(int i = 1; i < n - 1; i++) {
			printf("#");
			for(int j = 1; j < n - 1; j++) printf("J");
			printf("#\n");
		}
		for(int i = 0; i < n; i++) printf("#");
		printf("\n\n");
	}
}