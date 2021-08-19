#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int sum = 0, x;
	while(n--) {
		scanf("%d", &x);
		sum += x;
	}
	while(m--) {
		scanf("%d", &x);
		sum -= x;
	}
	printf("%d", sum);
}