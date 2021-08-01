#include <stdio.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a[2][7] = {};
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y]++;
	}
	int res = 0;
	for(auto &i : a) {
		for(int j = 1; j < 7; j++) {
			res += (i[j] + k - 1) / k;
		}
	}
	printf("%d", res);
}