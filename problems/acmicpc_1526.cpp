#include <stdio.h>
bool num(int n) {
	while(n) {
		auto const x = n % 10;
		if(x != 4 && x != 7) return false;
		n /= 10;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = n; i >= 0; i--) {
		if(num(i)) {
			printf("%d", i);
			return 0;
		}
	}
}