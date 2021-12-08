#include <stdio.h>
#include <string.h>
int main() {
	char s[999];
	scanf("%s", s);
	if(strlen(s) != 1 || s[0] != '1') putchar('1');
	else putchar('2');
}