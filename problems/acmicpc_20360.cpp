#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < 32; i++) {
		if(n & 1) printf("%d ", i);
		n >>= 1;
	}
}