#include <stdio.h>
using ll = long long;
ll p(int i) {
	if(i == 0) return 1;
	if(i == 1) return 31;
	auto const r = p(i / 2);
	return (((r * r) % 1234567891) * p(i % 2)) % 1234567891;
}
int main() {
	int n;
	scanf("%d", &n);
	auto s = new char[n + 1];
	scanf("%s", s);
	ll res = 0;
	for(int i = 0; i < n; i++) {
		res = (res + p(i) * (s[i] - 'a' + 1)) % 1234567891;
	}
	printf("%lld", res);
	delete[] s;
}