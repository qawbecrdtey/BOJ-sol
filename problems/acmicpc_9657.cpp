#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new bool[n + 1]();
	for(int i = 1; i <= n; i++) {
		if(!a[i - 1]) {
			a[i] = true;
			continue;
		}
		if(i > 2 && !a[i - 3]) {
			a[i] = true;
			continue;
		}
		if(i > 3 && !a[i - 4]) {
			a[i] = true;
			continue;
		}
	}
	printf(a[n] ? "SK" : "CY");
	delete[] a;
}