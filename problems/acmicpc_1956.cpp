#include <stdio.h>
constexpr int M = 98765432;
int main() {
	int v, m;
	scanf("%d%d", &v, &m);
	auto a = new int*[v + 1];
	for(int i = 1; i <= v; i++) {
		a[i] = new int[v + 1]();
		for(int j = 1; j <= v; j++) {
			if(i == j) continue;
			a[i][j] = M;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
	}
	for(int i = 1; i <= v; i++) {
		for(int s = 1; s <= v; s++) {
			for(int e = 1; e <= v; e++) {
				if(a[s][e] > a[s][i] + a[i][e]) a[s][e] = a[s][i] + a[i][e];
			}
		}
	}
	int min = M;
	for(int i = 1; i < v; i++) {
		for(int j = i + 1; j <= v; j++) {
			if(min > a[i][j] + a[j][i]) min = a[i][j] + a[j][i];
		}
	}
	if(min == M) printf("-1");
	else printf("%d", min);
	for(int i = 1; i <= v; i++) {
		delete[] a[i];
	}
	delete[] a;
}