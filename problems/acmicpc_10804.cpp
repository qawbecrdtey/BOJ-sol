#include <stdio.h>
int main() {
	int a[21] = {};
	for(int i = 1; i <= 20; i++) {
		a[i] = i;
	}
	for(int i = 0; i < 10; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for(int j = 0; j <= (y - x) / 2; j++) {
			int tmp = a[j + x];
			a[j + x] = a[y - j];
			a[y - j] = tmp;
		}
	}
	for(int i = 1; i <= 20; i++) {
		printf("%d ", a[i]);
	}
}