#include <cstdio>
int main() {
	char s[5]; scanf("%s", s);
	s[0] = (char)('E' + 'I' - s[0]);
	s[1] = (char)('S' + 'N' - s[1]);
	s[2] = (char)('T' + 'F' - s[2]);
	s[3] = (char)('J' + 'P' - s[3]);
	printf("%s", s);
}