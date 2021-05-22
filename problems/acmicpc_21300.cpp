#include <stdio.h>
int main() {
	int sum = 0;
	for(int i = 0; i < 6; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%d", sum * 5);
}