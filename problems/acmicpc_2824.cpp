#include <stdio.h>
using ll = long long;
ll gcd(ll a, ll b) {
	if(!b) return a;
	return gcd(b, a % b);
}
int main() {
	int n, m;
	scanf("%d", &n);
	auto a = new ll[n];
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &m);
	auto b = new ll[m];
	for(int i = 0; i < m; i++) {
		scanf("%lld", &b[i]);
	}
	bool big = false;
	ll res = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ll const g = gcd(a[i], b[j]);
			a[i] /= g; b[j] /= g;
			res *= g;
			if(res > 1000000000) {
				big = true;
				res %= 1000000000;
			}
		}
	}
	if(big) {
		printf("%09lld", res);
	}
	else printf("%lld", res);
	delete[] a;
	delete[] b;
}