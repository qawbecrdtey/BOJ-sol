#include <stdio.h>
void update(int *t, int tidx, int idx, int val, int l, int r) {
	if(idx < l || r < idx) return;
	t[tidx] += val;
	if(l == r) return;
	auto const m = (l + r) / 2;
	update(t, tidx * 2, idx, val, l, m);
	update(t, tidx * 2 + 1, idx, val, m + 1, r);
}
int kth(int *t, int tidx, int k, int l, int r) {
	t[tidx]--;
	if(l == r) return l;
	auto const m = (l + r) / 2;
	if(t[tidx * 2] >= k) return kth(t, tidx * 2, k, l, m);
	return kth(t, tidx * 2 + 1, k - t[tidx * 2], m + 1, r);
}
int main() {
	auto t = new int[4000000]();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == 1) {
			printf("%d\n", kth(t, 1, y, 1, 1000000));
		}
		else {
			int z;
			scanf("%d", &z);
			update(t, 1, y, z, 1, 1000000);
		}
	}
	delete[] t;
}