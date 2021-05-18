#include <stdio.h>
int main() {
	int x, y = 5000;
	while(scanf("%d", &x) != EOF) {
		switch(x) {
			case 1: y -= 500; break;
			case 2: y -= 800; break;
			case 3: y -= 1000; break;
			default: break;
		}
	}
	printf("%d", y);
}