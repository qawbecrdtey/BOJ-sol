#include <stdio.h>
int main() {
	int n, sum = 0, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
	}
	for(int i = 1; i < n; i++) {
		scanf("%d", &x);
		sum -= x;
	}
	printf("%d", sum);
}