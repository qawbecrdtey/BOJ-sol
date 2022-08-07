#include <cstdio>
inline int f(int lv) { return (1 << (lv + 3)) - lv - 5; }
char g(int n, int lv) {
	if(n > f(lv - 1) + lv + 3) return g(n - f(lv - 1) - lv - 3, lv - 1);
	if(n > f(lv - 1)) return (n - f(lv - 1) == 1 ? 'm' : 'o');
	return g(n, lv - 1);
}
int main() {
	int n; scanf("%d", &n);
	int lv = 0; while(f(lv) < n) lv++;
	printf("%c", g(n, lv));
}