#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if(i) a[i][j] += a[i - 1][j];
			if(j) a[i][j] += a[i][j - 1];
			if(i && j) a[i][j] -= a[i - 1][j - 1];
		}
	}
	while(m--) {
		int w, x, y, z;
		scanf("%d%d%d%d", &w, &x, &y, &z);
		int res = a[y - 1][z - 1];
		if(w > 1) res -= a[w - 2][z - 1];
		if(x > 1) res -= a[y - 1][x - 2];
		if(w > 1 && x > 1) res += a[w - 2][x - 2];
		printf("%d\n", res);
	}
}