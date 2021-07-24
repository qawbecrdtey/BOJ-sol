#include <stdio.h>
int main() {
	int n;
	scanf("%d\n", &n);
	while(n--) {
		char c;
		while(true) {
			scanf("%c", &c);
			if(c == ' ') break;
		}
		printf("god");
		while(true) {
			scanf("%c", &c);
			if(c < ' ') break;
			if(c == ' ') continue;
			printf("%c", c);
		}
		printf("\n");
	}
}