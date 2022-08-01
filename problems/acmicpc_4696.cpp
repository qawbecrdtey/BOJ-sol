#include <cstdio>
int main() {
	long double x;
	while(scanf("%Lf", &x)) {
		if(x == 0) return 0;
		printf("%.2Lf\n", 1 + (1 + (1 + (1 + x) * x) * x) * x);
	}
}