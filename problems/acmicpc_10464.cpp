#include <cstdio>
int calc(int n) {
	if(n % 4) return n ^ calc(n - 1);
	return n;
}
int main() {
	int t; scanf("%d", &t); while(t--) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", calc(a - 1) ^ calc(b));
	}
}