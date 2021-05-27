#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	int *a[4];
	for(auto &i : a) {
		i = new int[n];
	}
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);
	}
	auto x = new int[n * n];
	auto y = new int[n * n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			x[n * i + j] = a[0][i] + a[1][j];
			y[n * i + j] = a[2][i] + a[3][j];
		}
	}
	long long res = 0;
	std::sort(y, y + n * n);
	for(int i = 0; i < n * n; i++) {
		auto const l = std::lower_bound(y, y + n * n, -x[i]);
		if(*l != -x[i]) continue;
		auto const r = std::upper_bound(y, y + n * n, -x[i]);
		res += (r - l);
	}
	printf("%lld", res);
	delete[] y;
	delete[] x;
	for(auto &i : a) {
		delete[] i;
	}
}