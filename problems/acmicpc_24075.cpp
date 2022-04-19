#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int x[2]{ a + b, a - b };
	printf("%d\n%d", x[x[0] < x[1]], x[x[0] > x[1]]);
}