#include <cstdio>
constexpr long long M = 987654321;
int main() {
	int n; scanf("%d", &n);
	long long *a[10];
	for(auto &i : a) {
		i = new long long[n + 2]();
		i[1] = 1;
	} a[0][1] = 0;
	for(int i = 2; i <= n; i++) {
		a[1][i] = (a[1][i - 1] + a[2][i - 1] + a[3][i - 1]) % M;
		a[2][i] = (a[1][i - 1] + a[2][i - 1] + a[3][i - 1] + a[4][i - 1]) % M;
		a[3][i] = (a[1][i - 1] + a[2][i - 1] + a[3][i - 1] + a[4][i - 1] + a[5][i - 1]) % M;
		a[4][i] = (a[2][i - 1] + a[3][i - 1] + a[4][i - 1] + a[5][i - 1] + a[6][i - 1]) % M;
		a[5][i] = (a[3][i - 1] + a[4][i - 1] + a[5][i - 1] + a[6][i - 1] + a[7][i - 1]) % M;
		a[6][i] = (a[4][i - 1] + a[5][i - 1] + a[6][i - 1] + a[7][i - 1] + a[8][i - 1]) % M;
		a[7][i] = (a[5][i - 1] + a[6][i - 1] + a[7][i - 1] + a[8][i - 1] + a[9][i - 1]) % M;
		a[8][i] = (a[6][i - 1] + a[7][i - 1] + a[8][i - 1] + a[9][i - 1]) % M;
		a[9][i] = (a[7][i - 1] + a[8][i - 1] + a[9][i - 1]) % M;
	}
	long long res = 0;
	for(auto &i : a) {
		res = (res + i[n]) % M;
	} printf("%lld", res);
}