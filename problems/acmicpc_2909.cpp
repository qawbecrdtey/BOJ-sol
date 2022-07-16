#include <cstdio>
int main() {
	int a, b; scanf("%d%d", &a, &b);
	int r = 1; while(b--) { r *= 10; }
	if(r == 1) printf("%d", a);
	else printf("%d", (a / r + (a % r >= r / 2)) * r);
}