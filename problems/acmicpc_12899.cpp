#include <stdio.h>
void update(int *t, int tidx, int val, int l, int r) {
	t[tidx]++;
	if(l == r) return;
	auto const m = (l + r) / 2;
	if(l <= val && val <= m) update(t, tidx * 2, val, l, m);
	if(m + 1 <= val && val <= r) update(t, tidx * 2 + 1, val, m + 1, r);
}
int find(int *t, int tidx, int k, int l, int r) {
	t[tidx]--;
	if(l == r) return l;
	auto const m = (l + r) / 2;
	if(t[tidx * 2] >= k) return find(t, tidx * 2, k, l, m);
	return find(t, tidx * 2 + 1, k - t[tidx * 2], m + 1, r);
}
int main() {
	int n;
	scanf("%d", &n);
	auto t = new int[8000000]();
	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == 1) {
			update(t, 1, y, 1, 2000000);
		}
		else {
			printf("%d\n", find(t, 1, y, 1, 2000000));
		}
	}
	delete[] t;
}