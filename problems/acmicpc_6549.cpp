#include <cstdio>
int init(int *t, int *a, int idx, int left, int right) {
	if(left == right) return t[idx] = left;
	auto const m = (left + right) / 2;
	auto const x = init(t, a, idx * 2, left, m);
	auto const y = init(t, a, idx * 2 + 1, m + 1, right);
	if(x == 0) return y;
	if(y == 0) return x;
	return t[idx] = a[x] < a[y] ? x : y;
}
int min(int *t, int *a, int idx, int from, int to, int left, int right) {
	if(from > right || to < left) return 0;
	if(from <= left && right <= to) return t[idx];
	auto const m = (left + right) / 2;
	auto const x = min(t, a, idx * 2, from, to, left, m);
	auto const y = min(t, a, idx * 2 + 1, from, to, m + 1, right);
	return a[x] < a[y] ? x : y;
}
long long f(int *t, int *a, int n, int piv, int left, int right) {
	if(left == right) return (long long)a[piv];
	auto max = (long long)a[piv] * (right - left + 1);

	auto const l = min(t, a, 1, left, piv - 1, 1, n);
	auto const r = min(t, a, 1, piv + 1, right, 1, n);
	if(l != 0) {
		auto const x = f(t, a, n, l, left, piv - 1);
		if(max < x) max = x;
	}
	if(r != 0) {
		auto const y = f(t, a, n, r, piv + 1, right);
		if(max < y) max = y;
	}
	return max;
}
int main() {
	while(true) {
		int n;
		scanf("%d", &n);
		if(n == 0) return 0;
		auto a = new int[n + 1];
		auto t = new int[n * 4]();
		a[0] = 1000000001;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		init(t, a, 1, 1, n);
		printf("%lld\n", f(t, a, n, min(t, a, 1, 1, n, 1, n), 1, n));
	}
}