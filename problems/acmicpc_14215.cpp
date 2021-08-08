#include <algorithm>
#include <stdio.h>
int main() {
	int a[3];
	scanf("%d%d%d", a, a + 1, a + 2);
	std::sort(a, a + 3);
	if(a[2] < a[1] + a[0]) printf("%d", a[0] + a[1] + a[2]);
	else printf("%d", (a[1] + a[0]) * 2 - 1);
}