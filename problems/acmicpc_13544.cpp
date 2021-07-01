#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
void init(vector<int> *t, int const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx].push_back(a[l]);
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx].resize(t[tidx * 2].size() + t[tidx * 2 + 1].size());
	merge(t[tidx * 2].begin(), t[tidx * 2].end(), t[tidx * 2 + 1].begin(), t[tidx * 2 + 1].end(), t[tidx].begin());
}
long long gt(vector<int> const *t, int const *a, int tidx, long long start, long long end, long long k, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return t[tidx].end() - upper_bound(t[tidx].begin(), t[tidx].end(), k);
	auto const m = (l + r) / 2;
	auto const x = gt(t, a, tidx * 2, start, end, k, l, m);
	auto const y = gt(t, a, tidx * 2 + 1, start, end, k, m + 1, r);
	return x + y;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new vector<int>[n * 4];
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	int m;
	scanf("%d", &m);
	long long res = 0;
	while(m--) {
		long long x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		x ^= res;
		y ^= res;
		z ^= res;
		printf("%lld\n", res = gt(t, a, 1, x, y, z, 1, n));
	}
	delete[] t;
	delete[] a;
}