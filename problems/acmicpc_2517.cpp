#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void init(vector<int> *v, int const *a, int tidx, int l, int r) {
	if(l == r) {
		v[tidx].push_back(a[l]);
		return;
	}
	auto const m = ((l + r) >> 1);
	init(v, a, tidx << 1, l, m);
	init(v, a, (tidx << 1) | 1, m + 1, r);
	v[tidx].resize(r - l + 1);
	merge(v[tidx << 1].begin(), v[tidx << 1].end(), v[(tidx << 1) | 1].begin(), v[(tidx << 1) | 1].end(), v[tidx].begin());
}
uint64_t great(vector<int> const *v, int tidx, int start, int end, int val, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return v[tidx].end() - upper_bound(v[tidx].begin(), v[tidx].end(), val);
	auto const m = ((l + r) >> 1);
	auto const x = great(v, tidx << 1, start, end, val, l, m);
	auto const y = great(v, (tidx << 1) | 1, start, end, val, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	auto t = new vector<int>[n << 2];
	init(t, a, 1, 1, n);
	cout << "1\n";
	for(int i = 2; i <= n; i++) {
		cout << great(t, 1, 1, i - 1, a[i], 1, n) + 1 << '\n';
	}
	delete[] a;
	delete[] t;
}