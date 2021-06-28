#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if(n % 2) printf("%d", (n * n - 1) / 4);
	else printf("%d", n * n / 4);
}