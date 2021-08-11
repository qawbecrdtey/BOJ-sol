#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) a[i] = -1;
	for(int i = 1; i <= n; i++) {
		if(i > 1 && a[i - 2] != -1) a[i] = a[i - 2] + 1;
		if(i > 4 && a[i - 5] != -1 && (a[i] == -1 || a[i - 5] < a[i])) a[i] = a[i - 5] + 1;
	}
	if(!a[n]) printf("-1");
	else printf("%d", a[n]);
}