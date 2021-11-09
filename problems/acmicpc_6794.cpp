#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i + i <= n && i < 6; i++) {
		cnt += (n - i < 6);
	}
	printf("%d", cnt);
}