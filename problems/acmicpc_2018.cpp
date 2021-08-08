#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int l = 1, r = 1;
	int val = 0;
	int cnt = 1;
	while(l < n) {
		if(val == n) cnt++;
		if(r == n) {
			val -= l++;
		}
		if(l == r) {
			val += r++;
			continue;
		}
		if(val < n) {
			val += r++;
			continue;
		}
		if(val > n) {
			val -= l++;
			continue;
		}
		val += r++;
	}
	printf("%d", cnt);
}