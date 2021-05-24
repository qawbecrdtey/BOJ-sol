#include <stdio.h>
int sign(int x) { return (x == 0 ? 0 : (x > 0 ? 1 : -1)); }
int init(int *t, int const *a, int tidx, int left, int right) {
	if(left == right) return t[tidx] = sign(a[left]);
	auto const m = (left + right) / 2;
	auto const x = init(t, a, tidx * 2, left, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, right);
	return t[tidx] = x * y;
}
int update(int *t, int *a, int tidx, int ato, int idx, int left, int right) {
	if(left > idx || right < idx) return t[tidx];
	if(left == right) {
		return t[tidx] = sign(a[idx] = ato);
	}
	auto const m = (left + right) / 2;
	auto const x = update(t, a, tidx * 2, ato, idx, left, m);
	auto const y = update(t, a, tidx * 2 + 1, ato, idx, m + 1, right);
	return t[tidx] = x * y;
}
int mul(int *t, int *a, int tidx, int start, int end, int left, int right) {
	if(right < start || left > end) return 1;
	if(start <= left && right <= end) return t[tidx];
	auto const m = (left + right) / 2;
	auto const x = mul(t, a, tidx * 2, start, end, left, m);
	auto const y = mul(t, a, tidx * 2 + 1, start, end, m + 1, right);
	return x * y;
}
int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		auto a = new int[n + 1];
		auto t = new int[n * 4]();
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		init(t, a, 1, 1, n);
		while(k--) {
			char s[2];
			int x, y;
			scanf("%s%d%d", s, &x, &y);
			switch(s[0]) {
				case 'C': update(t, a, 1, y, x, 1, n); break;
				case 'P': {
					switch(mul(t, a, 1, x, y, 1, n)) {
						case -1: printf("-"); break;
						case 0: printf("0"); break;
						case 1: printf("+"); break;
						default: return 1;
					} break;
				}
				default: return 1;
			}
		}
		printf("\n");
		delete[] a;
	}
}