#include <stdio.h>
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		__int128 sum = 0;
		for(int i = 0; i < n; i++) {
			long long x;
			scanf("%lld", &x);
			sum += x;
		}
		printf(sum == 0 ? "0\n" : (sum > 0 ? "+\n" : "-\n"));
	}
}