#include <cstdio>
int main() {
	unsigned int n, m, i = 0, c = 0; scanf("%u", &n);
	m = (~n) + 1;
	for(; i < 32; i++) c += (((n ^ m) >> i) & 1);
	printf("%u", c);
}