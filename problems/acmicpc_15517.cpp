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
	t[tidx].resize(r - l + 1);
	merge(t[tidx * 2].begin(), t[tidx * 2].end(), t[tidx * 2 + 1].begin(), t[tidx * 2 + 1].end(), t[tidx].begin());
}
long long le(vector<int> const *t, int const *a, int tidx, int idx, int start, int end, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) {
		return lower_bound(t[tidx].begin(), t[tidx].end(), a[idx]) - t[tidx].begin();
	}
	auto const m = (l + r) / 2;
	auto const x = le(t, a, tidx * 2, idx, start, end, l, m);
	auto const y = le(t, a, tidx * 2 + 1, idx, start, end, m + 1, r);
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
	printf("0\n");
	for(int i = 2; i <= n; i++) {
		printf("%lld\n", le(t, a, 1, i, 1, i - 1, 1, n));
	}
	delete[] t;
	delete[] a;
}