#include <cstdio>
int main() {
	int a, b, c, d;
	while(true) {
		scanf("%d:%d %d:%d", &a, &b, &c, &d);
		if(!a && !b && !c && !d) return 0;
		int n = 0;
		b += d; if(b >= 60) b -= 60, a++;
		a += c; while(a >= 24) a -= 24, n++;
		printf("%02d:%02d", a, b);
		if(n) printf(" +%d", n);
		printf("\n");
	}
}