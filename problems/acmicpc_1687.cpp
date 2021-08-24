#include <stdio.h>
#include <algorithm>
int init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] < a[y] ? x : y);
}
int mini(int const *t, int const *a, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[x] < a[y] ? x : y;
}
int f(int const *t, int const *a, int n, int l, int r) {
	if(l > r) return 0;
	if(l == r) return a[l];
	auto const m = mini(t, a, 1, l, r, 1, n);
	auto res = a[m] * (r - l + 1);
	auto const x = f(t, a, n, l, m - 1);
	auto const y = f(t, a, n, m + 1, r);
	if(res < x) res = x;
	if(res < y) res = y;
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char[m + 2];
	auto arr = new int*[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m + 1];
		scanf("%s", a + 1);
		for(int j = 1; j <= m; j++) {
			if(a[j] == '1') arr[i][j] = 0;
			else {
				arr[i][j] = 1;
				if(i) arr[i][j] += arr[i - 1][j];
			}
		}
	}
	delete[] a;
	int max = 0;
	auto t = new int[m * 4];
	for(int i = 0; i < n; i++) {
		init(t, arr[i], 1, 1, m);
		auto const x = f(t, arr[i], m, 1, m);
		if(max < x) max = x;
		delete[] arr[i];
	}
	delete[] t;
	printf("%d", max);
	delete[] arr;
}