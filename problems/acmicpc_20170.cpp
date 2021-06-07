#include <stdio.h>
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int a[6], b[6];
	for(auto &i : a) scanf("%d", &i);
	for(auto &i : b) scanf("%d", &i);
	int cnt = 0;
	for(auto i : a) {
		for(auto j : b) {
			if(i > j) cnt++;
		}
	}
	int g = gcd(cnt, 36);
	printf("%d/%d", cnt / g, 36 / g);
}