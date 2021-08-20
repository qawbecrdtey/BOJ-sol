#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int a, b, res;
		scanf("%d%d", &a, &b);
		if(!a) res = 0;
		else if(a == 1) res = 5000000;
		else if(a <= 3) res = 3000000;
		else if(a <= 6) res = 2000000;
		else if(a <= 10) res = 500000;
		else if(a <= 15) res = 300000;
		else if(a <= 21) res = 100000;
		else res = 0;
		if(!b) res += 0;
		else if(b == 1) res += 5120000;
		else if(b <= 3) res += 2560000;
		else if(b <= 7) res += 1280000;
		else if(b <= 15) res += 640000;
		else if(b <= 31) res += 320000;
		printf("%d\n", res);
	}
}