#include <algorithm>
#include <stdio.h>
using ll = unsigned long long;
constexpr ll M = 1000000007;
void del(int n, ll** a) {
	for(int i = 1; i <= n; i++) delete[] a[i];
	delete[] a;
}
ll** mul(int n, ll const* const *a, ll const* const* b) {
	auto res = new ll*[n + 1];
	for(int i = 1; i <= n; i++) {
		res[i] = new ll[n + 1]();
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				res[i][j] += (a[i][k] * b[k][j]) % M;
				res[i][j] %= M;
			}
		}
	}
	return res;
}
ll** power(ll const* const* orig, int n, ll d) {
	if(!d) {
		auto res = new ll*[n + 1];
		for(int i = 1; i <= n; i++) {
			res[i] = new ll[n + 1]();
			res[i][i] = 1;
		}
		return res;
	}
	if(d == 1) {
		auto res = new ll*[n + 1];
		for(int i = 1; i <= n; i++) {
			res[i] = new ll[n + 1];
			std::copy(orig[i], orig[i] + n + 1, res[i]);
		}
		return res;
	}
	ll **res, **b, **c;
	b = power(orig, n, d >> 1);
	c = mul(n, b, b);
	del(n, b);
	b = power(orig, n, d & 1);
	res = mul(n, c, b);
	del(n, b);
	del(n, c);
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto orig = new ll*[n + 1];
	for(int i = 1; i <= n; i++) {
		orig[i] = new ll[n + 1]();
	}
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		orig[x][y] = orig[y][x] = 1;
	}
	ll d; scanf("%llu", &d);
	auto res = power(orig, n, d);
	printf("%llu", res[1][1]);
	del(n, res);
}