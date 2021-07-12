#include <stdio.h>
using ll = long long;
constexpr ll m = 1000000000;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll**[n + 1];
	for(int i = 1; i <= n; i++) {
		a[i] = new ll*[10];
		for(int j = 0; j < 10; j++) {
			a[i][j] = new ll[1024]();
		}
		if(i == 1) {
			for(int j = 1; j < 10; j++) {
				a[1][j][1 << j] = 1;
			}
			continue;
		}
		for(int k = 0; k < 1024; k++) {
			for(int j = 0; j < 9; j++) {
				a[i][j + 1][k | (1 << (j + 1))] = (a[i][j + 1][k | (1 << (j + 1))] + a[i - 1][j][k]) % m;
				a[i][j][k | (1 << j)] = (a[i][j][k | (1 << j)] + a[i - 1][j + 1][k]) % m;
			}
		}
	}
	ll sum = 0;
	for(int i = 0; i < 10; i++) {
		sum = (sum + a[n][i][1023]) % m;
	}
	printf("%lld", sum);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 10; j++) {
			delete[] a[i][j];
		}
		delete[] a[i];
	}
	delete[] a;
}