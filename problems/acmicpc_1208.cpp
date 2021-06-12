#include <stdio.h>
#include <algorithm>
int power(int n) {
	if(n < 2) return n + 1;
	auto const r = power(n / 2);
	return r * r * power(n % 2);
}
void g(int const *a, bool *b, int *c, int n, int &idx, int cur) {
	if(cur == n) {
		for(int i = 0; i < n; i++) {
			if(b[i]) c[idx] += a[i];
		}
		idx++;
		return;
	}
	b[cur] = false;
	g(a, b, c, n, idx, cur + 1);
	b[cur] = true;
	g(a, b, c, n, idx, cur + 1);
}
int *f(int const *a, int n) {
	auto c = new int[power(n)]();
	auto b = new bool[n]();
	int idx = 0;
	g(a, b, c, n, idx, 0);
	delete[] b;
	return c;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n / 2];
	auto b = new int[n - n / 2];
	for(int i = 0; i < n / 2; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n - n / 2; i++) {
		scanf("%d", &b[i]);
	}
	auto c = f(a, n / 2);
	auto d = f(b, n - n / 2);
	long long sum = 0;
	int const na = power(n / 2);
	int const nb = power(n - n / 2);
	std::sort(c + 1, c + na);
	std::sort(d + 1, d + nb);
	sum += (std::upper_bound(c + 1, c + na, m) - std::lower_bound(c + 1, c + na, m));
	sum += (std::upper_bound(d + 1, d + nb, m) - std::lower_bound(d + 1, d + nb, m));
	for(int i = 1; i < na; i++) {
		sum += (std::upper_bound(d + 1, d + nb, m - c[i]) - std::lower_bound(d + 1, d + nb, m - c[i]));
	}
	printf("%lld", sum);
	delete[] a;
	delete[] c;
	delete[] d;
}