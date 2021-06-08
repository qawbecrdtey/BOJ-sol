#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) {
		printf("A");
		return 0;
	}
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if(n == 2) {
		if(a[0] == a[1]) printf("%d", a[0]);
		else printf("A");
		goto END;
	}
	if(a[0] == a[1]) {
		for(int i = 2; i < n; i++) {
			if(a[i] != a[0]) {
				printf("B");
				goto END;
			}
		}
		printf("%d", a[0]);
		goto END;
	}
	if(((a[2] - a[1]) / (a[1] - a[0])) * (a[1] - a[0]) == a[2] - a[1]) {
		int x = (a[2] - a[1]) / (a[1] - a[0]);
		int y = a[1] - x * a[0];
		for(int i = 2; i < n - 1; i++) {
			if(a[i + 1] != x * a[i] + y) {
				printf("B");
				goto END;
			}
		}
		printf("%d", x * a[n - 1] + y);
	}
	else printf("B");
	END:
	delete[] a;
}