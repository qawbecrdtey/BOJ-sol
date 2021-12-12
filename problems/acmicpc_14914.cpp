#include <stdio.h>
int gcd(int a, int b) { if(!b) return a; return gcd(b, a % b); }
int main() {
	int a, b; scanf("%d%d", &a, &b);
	int g = gcd(a, b);
	for(int i = 1; i <= g; i++) {
		if(g % i == 0) printf("%d %d %d\n", i, a / i, b / i);
	}
}