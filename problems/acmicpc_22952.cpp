#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	if(n & 1) printf("%d ", n);
	for(int i = 1; i <= n / 2; i++) {
		if(i * 2 == n) printf("%d %d", i, n);
		else printf("%d %d ", i, n - i);
	}
}