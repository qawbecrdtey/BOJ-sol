#include <cstdio>
int main() {
	int a, b; scanf("%d%d", &a, &b);
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			printf("*");
		} if(i != a - 1) printf("\n");
	}
}