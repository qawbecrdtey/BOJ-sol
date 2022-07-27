#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	for(int i = n - n / 2; i; i--) {
		printf("%d ", i);
		if(!(i == 1 && (n & 1))) printf("%d ", i + n / 2);
	}
}