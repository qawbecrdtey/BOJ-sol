#include <stdio.h>
int p(int n) {
	if(n < 2) return n + 1;
	auto const r = p(n / 2);
	return r * r * p(n % 2);
}
int f(int n, int r, int c) {
	if(n == 0) return 0;
	auto const l = p(n) / 2;
	if(r < l) {
		if(c < l) return f(n - 1, r, c);
		return l * l + f(n - 1, r, c - l);
	}
	else {
		if(c < l) return l * l * 2 + f(n - 1, r - l, c);
		return l * l * 3 + f(n - 1, r - l, c - l);
	}
}
int main() {
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	printf("%d", f(n, r, c));
}