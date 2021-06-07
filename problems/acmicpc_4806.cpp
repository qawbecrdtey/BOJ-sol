#include <stdio.h>
int main() {
	char c;
	int cnt = 0;
	while(scanf("%c", &c) != EOF) {
		if(c == '\n') cnt++;
	}
	printf("%d", cnt);
}