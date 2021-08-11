#include <stdio.h>
int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	auto a = new char[w + 1];
	while(h--) {
		int cur = -1;
		scanf("%s", a);
		for(int i = 0; i < w; i++) {
			if(a[i] == 'c') cur = 0;
			printf("%d ", cur);
			if(cur != -1) cur++;
		}
		printf("\n");
	}
	delete[] a;
}