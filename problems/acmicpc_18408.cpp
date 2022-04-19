#include <cstdio>
int main() {
	int sum = 0, a;
	for(int i = 0; i < 3; i++) {
		scanf("%d", &a);
		sum += a;
	} printf("%d", 1 + (sum > 4));
}