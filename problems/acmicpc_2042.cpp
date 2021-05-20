#include <stdio.h>
using ll = long long;
void update(ll *t, int n, int i, ll val) {
	while(i <= n) {
		t[i] += val;
		i += (i & -i);
	}
}
ll sum(ll const *t, int n, int i) {
	ll ans = 0;
	while(i) {
		ans += t[i];
		i -= (i & -i);
	}
	return ans;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	auto a = new ll[n + 1];
	auto t = new ll[n + 1]();
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		update(t, n, i, a[i]);
	}
	for(int i = 0; i < m + k; i++) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if(x == 1) {
			update(t, n, y, z - a[y]);
			a[y] = z;
		}
		else if(x == 2) {
			printf("%lld\n", sum(t, n, z) - sum(t, n, y - 1));
		}
	}
	delete[] t;
	delete[] a;
}