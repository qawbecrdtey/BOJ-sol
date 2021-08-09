#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int w, x, y, z;
		scanf("%d%d%d%d", &w, &x, &y, &z);
		y--; z--;
		bool flag = false;
		for(long long i = z; i <= w * x; i += x) {
			if(i % w == y) {
				printf("%lld\n", i + 1);
				flag = true;
				break;
			}
		}
		if(!flag) {
			printf("-1\n");
		}
	}
}