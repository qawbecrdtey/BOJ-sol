#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		while(x--) printf("=");
		printf("\n");
	}
}