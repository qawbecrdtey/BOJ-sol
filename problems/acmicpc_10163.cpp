#include <stdio.h>
int main() {
	auto a = new int*[1001];
	for(int i = 0; i <= 1000; i++) {
		a[i] = new int[1001]();
	}
	int n;
	scanf("%d", &n);
	for(int t = 1; t <= n; t++) {
		int w, x, y, z;
		scanf("%d%d%d%d", &w, &x, &y, &z);
		for(int i = 0; i < y; i++) {
			for(int j = 0; j < z; j++) {
				a[i + w][j + x] = t;
			}
		}
	}
	auto arr = new int[n + 1]();
	for(int i = 0; i <= 1000; i++) {
		for(int j = 0; j <= 1000; j++) {
			arr[a[i][j]]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}
}