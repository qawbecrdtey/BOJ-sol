#include <stdio.h>
int main() {
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
	long double x = (long double)a / d, y = (long double)b / e, z = (long double)c / f;
	if(x <= y && x <= z) {
		printf("0 %Lf %Lf", b - x * e, c - x * f);
	}
	else if(y <= x && y <= z) {
		printf("%Lf 0 %Lf", a - y * d, c - y * f);
	}
	else if(z <= x && z <= y) {
		printf("%Lf %Lf 0", a - z * d, b - z * e);
	}
}