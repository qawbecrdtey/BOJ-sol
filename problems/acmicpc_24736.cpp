#include <cstdio>
int main() {
	while(true) {
		int a[5];
		for (int &i: a) if (scanf("%d", &i) == EOF) return 0;
		printf("%d ", a[0] * 6 + a[1] * 3 + a[2] * 2 + a[3] * 1 + a[4] * 2);
	}
}