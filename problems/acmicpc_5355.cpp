#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		long double x;
		scanf("%Lf ", &x);
		char c, d;
		while(true) {
			scanf("%c%c", &c, &d);
			if(c == '@') x *= 3;
			else if(c == '%') x += 5;
			else if(c == '#') x -= 7;
			if(d == '\n') break;
		}
		printf("%.2Lf\n", x);
	}
}