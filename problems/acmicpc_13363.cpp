#include <cstdio>
int main() {
	int a, b; scanf("%d%d", &a, &b);
	if(b < a) b += 360;
	int c = b - a;
	if(c > 180) c -= 360;
	printf("%d", c);
}