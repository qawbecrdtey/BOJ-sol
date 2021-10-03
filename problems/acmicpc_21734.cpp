#include <string.h>
#include <stdio.h>
int main() {
	char c[100];
	scanf("%s", c);
	auto l = strlen(c);
	for(int i = 0; i < l; i++) {
		int x = c[i];
		int cnt = 0;
		while(x) {
			cnt += x % 10;
			x /= 10;
		}
		for(int j = 0; j < cnt; j++) {
			printf("%c", c[i]);
		}
		printf("\n");
	}
}