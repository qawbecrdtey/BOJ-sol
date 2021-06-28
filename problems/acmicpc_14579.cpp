#include <stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int mul = 1;
	for(int i = a; i <= b; i++) {
		mul = (mul * (((i * (i + 1)) / 2) % 14579)) % 14579;
	}
	printf("%d", mul);
}