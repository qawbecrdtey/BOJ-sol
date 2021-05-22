#include <stdio.h>
int main() {
	int n, a, b, c;
	scanf("%d%d%d%d",&n, &a, &b, &c);
	int x = (a / c) * (b / c);
	printf("%d", n < x ? n : x);
}