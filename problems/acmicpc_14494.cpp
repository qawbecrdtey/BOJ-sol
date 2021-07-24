#include <stdio.h>
constexpr int M = 1000000007;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int*[n + 1];
	for(int i = 0; i <= n; i++) {
		a[i] = new int[m + 1]();
	}
	a[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = ((a[i - 1][j] + a[i][j - 1]) % M + a[i - 1][j - 1]) % M;
		}
	}
	printf("%d", a[n][m]);
}