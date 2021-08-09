#include <stdio.h>
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < m; i++) {
		printf("%c", 'a' + (i / 2) % n);
	}
}