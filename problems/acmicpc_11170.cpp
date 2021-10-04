#include <stdio.h>
int main() {
	auto zero = new int[1000001]();
	zero[0] = 1;
	for(int i = 1; i <= 1000000; i++) {
		zero[i] = zero[i - 1];
		int x = i;
		int cnt = 0;
		while(x) {
			zero[i] += (x % 10 == 0);
			x /= 10;
		}
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(!x) printf("%d\n", zero[y]);
		else printf("%d\n", zero[y] - zero[x - 1]);
	}
}