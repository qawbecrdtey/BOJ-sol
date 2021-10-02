#include <stdio.h>
int main() {
	int n, x = 0; long long sum = 0; char c;
	scanf("%d\n", &n);
	while(n--) {
		scanf("%c", &c);
		if(c >= '0' && c <= '9') {
			x *= 10;
			x += c - '0';
			continue;
		}
		sum += x;
		x = 0;
	}
	sum += x;
	printf("%lld", sum);
}