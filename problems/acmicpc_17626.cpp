#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1]();
	for(int i = 1; i <= n; i++) {
		a[i] = 4;
		for(int j = 1; j * j <= i; j++) {
			if(a[i] > a[i - j * j] + 1) a[i] = a[i - j * j] + 1;
		}
	}
	printf("%d", a[n]);
}