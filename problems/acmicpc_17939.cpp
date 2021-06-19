#include <stdio.h>
using namespace std;
int init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[y] >= a[x] ? y : x);
}
int maxi(int *t, int const *a, int tidx, int start, int end, int l, int r) {
	if(r < start || l > end) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = maxi(t, a, tidx * 2, start, end, l, m);
	auto const y = maxi(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[y] >= a[x] ? y : x;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new int[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	int l = 1;
	int sum = 0;
	while(l < n) {
		int const idx = maxi(t, a, 1, l, n, 1, n);
		for(int i = l; i < idx; i++) {
			sum += a[idx] - a[i];
		}
		l = idx + 1;
	}
	printf("%d", sum);
}