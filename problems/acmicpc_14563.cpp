#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i * i <= n; i++) {
			if(n % i == 0) {
				sum += i;
				if(i * i != n) sum += n / i;
			}
		}
		if(sum == (n << 1)) printf("Perfect\n");
		else if(sum < (n << 1)) printf("Deficient\n");
		else printf("Abundant\n");
	}
}