#include <cstdio>
inline int count(int a, int b) {
	int res = 0;
	while(a) {
		res += (a % 10 == b);
		a /= 10;
	} return res;
}
int main() {
	int n, m, sum = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		sum += count(i, m);
	} printf("%d", sum);
}