#include <stdio.h>
int main() {
	long long n;
	scanf("%lld", &n);
	long long cnt = 0;
	while(n != 1) {
		if(n % 2 == 0) {
			n /= 2;
		}
		else {
			n++;
		}
		cnt++;
	}
	printf("%lld", cnt);
}