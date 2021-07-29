#include <stdio.h>
using ll = long long;
constexpr ll M = 1000000007;
int main() {
	auto a = new ll*[1001];
	for(int i = 0; i <= 1000; i++) {
		a[i] = new ll[i + 1];
		a[i][0] = a[i][i] = 1;
		for(int j = 1; j < i; j++) {
			a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % M;
		}
	}
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", a[x][y]);
	}
}