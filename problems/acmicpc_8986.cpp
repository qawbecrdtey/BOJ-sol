#include <stdio.h>
using ll = long long;
ll abs(ll a) { return a > 0 ? a : -a; }
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n];
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	ll l = 1, r = 1000000000;
	ll res = 1000000000000000;
	while(r - l > 3) {
		auto const m1 = (l * 2 + r) / 3;
		auto const m2 = (l + r * 2) / 3;
		ll sum1 = 0, sum2 = 0;
		int cnt = 0;
		for(ll i = a[0]; cnt < n; cnt++, i += m1) {
			sum1 += abs(a[cnt] - i);
		}
		cnt = 0;
		for(ll i = a[0]; cnt < n; cnt++, i += m2) {
			sum2 += abs(a[cnt] - i);
		}
		if(sum1 < sum2) {
			r = m2;
			if(res > sum1) res = sum1;
			continue;
		}
		l = m1;
		if(res > sum2) res = sum2;
	}
	for(auto i = l; i <= r; i++) {
		int cnt = 0;
		ll sum = 0;
		for(ll j = a[0]; cnt < n; cnt++, j += i) {
			sum += abs(a[cnt] - j);
		}
		if(res > sum) res = sum;
	}
	printf("%lld", res);
	delete[] a;
}