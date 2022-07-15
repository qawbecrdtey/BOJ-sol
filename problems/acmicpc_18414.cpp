#include <cstdio>
int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	if(a < b) printf("%d", b);
	else if(a < c) printf("%d", a);
	else printf("%d", c);
}