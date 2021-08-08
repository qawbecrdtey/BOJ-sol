#include <stdio.h>
int abs(int x) { return x > 0 ? x : -x; }
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d", abs(a + d - b - c));
}