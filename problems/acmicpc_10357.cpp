#include <cstdio>
using ll = long long;
int main() {
	ll m, n; scanf("%lld%lld", &m, &n);
	ll res = 0;
	for(int x = 0; x <= m; x++) {
		for(int y = x; y <= m; y++) {
			for(int z = y; z <= m; z++) {
				res += (x * x + y * y == z * z);
			}
		}
	} printf("%lld", res + (m + 1) * (n - 2));
}