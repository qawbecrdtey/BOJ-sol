#include <stdio.h>
using ll = long long;
ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main() {
	int d, m;
	scanf("%d%d", &d, &m);
	ll g, l;
	scanf("%lld", &l);
	d--;
	while(d--) {
		ll x;
		scanf("%lld", &x);
		l = lcm(l, x);
	}
	scanf("%lld", &g);
	m--;
	while(m--) {
		ll x;
		scanf("%lld", &x);
		g = gcd(g, x);
	}
	if(g % l != 0) {
		printf("0"); return 0;
	}
	g /= l;
	int cnt = 0;
	for(int i = 1; i * i <= g; i++) {
		if(g % i == 0) {
			cnt++;
			if (i * i != g) cnt++;
		}
	}
	printf("%d", cnt);
}