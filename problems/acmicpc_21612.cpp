#include <cstdio>
int main() {
	int b; scanf("%d", &b);
	printf("%d\n%d", 5 * b - 400, (b > 100 ? -1 : (b == 100 ? 0 : 1)));

}