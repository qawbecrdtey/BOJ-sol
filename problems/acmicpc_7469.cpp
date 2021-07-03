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
int leq(vector<int> const *t, int const *a, int tidx, int start, int end, long long val, int l, int r) {
	if(r < start || end < l) return 0;
	if(start <= l && r <= end) return static_cast<int>(upper_bound(t[tidx].begin(), t[tidx].end(), val) - t[tidx].begin());
	auto const m = (l + r) / 2;
	auto const x = leq(t, a, tidx * 2, start, end, val, l, m);
	auto const y = leq(t, a, tidx * 2 + 1, start, end, val, m + 1, r);
	return x + y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n + 1];
	auto t = new vector<int>[n * 4]();
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += 1000000000;
	}
	init(t, a, 1, 1, n);
	while(m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		long long l = 0, r = 2000000001;
		while(l < r) {
			auto const mid = (l + r) / 2;
			auto const res = leq(t, a, 1, x, y, mid, 1, n);
			if(res < z) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		printf("%lld\n", l - 1000000000);
	}
	delete[] a;
	delete[] t;
}