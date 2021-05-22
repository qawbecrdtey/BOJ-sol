#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int res = 1;
	while(n > 5) {
		n -= 3;
		res = (res * 3) % 10007;
	}
	switch(n) {
		case 3: res = (res * 3) % 10007; break;
		case 4: res = (res * 4) % 10007; break;
		case 5: res = (res * 6) % 10007; break;
		default: res = n; break;
	}
	printf("%d", res);
}