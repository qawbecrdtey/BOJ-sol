#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int x = n;
	if(n == 1) {
		printf("1");
		return 0;
	}
	auto a = new int[n];
	for(int i = 1; i <= n; i++) a[i - 1] = i;
	while(n > 1) {
		for(int i = 0; i < n / 2; i++) {
			a[i] = a[i * 2 + 1];
		}
		n /= 2;
	}
	printf("%d", a[0]);
}