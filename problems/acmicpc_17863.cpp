#include <cstdio>
int main() {
	char c[8];
	scanf("%s", c);
	if(c[0] == '5' && c[1] == c[2] && c[1] == '5') printf("YES");
	else printf("NO");
}