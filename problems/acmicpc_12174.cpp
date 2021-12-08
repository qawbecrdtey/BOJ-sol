#include <stdio.h>
inline char read() {
	char c, res = 0;
	int cnt = 0;
	while(cnt < 8) {
		c = getchar();
		if(c != 'I' && c != 'O') continue;
		res <<= 1; res += (c == 'I');
		cnt++;
	}
	return res;
}
int main() {
	int t; scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		printf("Case #%d: ", tt);
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			putchar(read());
		}
		putchar('\n');
	}
}