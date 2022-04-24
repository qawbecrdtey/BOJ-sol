#include <cstdio>
int main() {
	char a[41];
	int t; scanf("%d", &t); while(t--) {
		scanf("%s", a);
		int b[8]{};
		for(int i = 0; i < 38; i++) {
			int x = 0;
			for(int j = 0; j < 3; j++) {
				x = (x << 1) | (a[i + j] == 'H');
			} b[x]++;
		} for(int i: b) {
			printf("%d ", i);
		} printf("\n");
	}
}