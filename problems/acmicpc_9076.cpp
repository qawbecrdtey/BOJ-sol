#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int a[5];
		for(int & i : a) {
			scanf("%d", &i);
		}
		std::sort(a, a + 5);
		if(a[3] - a[1] > 3) printf("KIN\n");
		else printf("%d\n", a[1] + a[2] + a[3]);
	}
}