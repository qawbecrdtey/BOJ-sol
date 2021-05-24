#include <stdio.h>
bool f(int x) {
	int cnt = 0;
	while(x) {
		if(x % 10 == 6) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		if(cnt == 3) return true;
		x /= 10;
	}
	return false;
}
int main() {
	int n;
	scanf("%d", &n);
	int num = 666;
	int cnt = 0;
	while(cnt < n) {
		if(f(num)) cnt++;
		if(cnt == n) break;
		num++;
	}
	printf("%d", num);
}