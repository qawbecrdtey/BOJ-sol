#include <stdio.h>
#include <cmath>
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}
int main() {
	int n; scanf("%d", &n);
	int x; scanf("%d", &x);
	int g = x;
	for(int i = 1; i < n; i++) {
		int a; scanf("%d", &a);
		if(i == 1) g = abs(x - a);
		else g = gcd(g, abs(x - a));
	}
	printf("%d", g);
}