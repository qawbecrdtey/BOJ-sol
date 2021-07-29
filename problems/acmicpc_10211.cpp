#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		auto a = new int[n];
		int sum = 0;
		int max = -10000000;
		int maxv = -10000000;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if(sum + a[i] < 0) sum = 0;
			else sum += a[i];
			if(max < sum) max = sum;
			if(maxv < a[i]) maxv = a[i];
		}
		if(!max) {
			max = maxv;
		}
		printf("%d\n", max);
		delete[] a;
	}
}