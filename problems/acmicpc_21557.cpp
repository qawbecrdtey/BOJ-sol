#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[0]--;
	a[n - 1]--;
	for(int i = 0; i < n - 3; i++) {
		if(a[0] >= a[n - 1]) a[0]--;
		else a[n - 1]--;
	}
	printf("%d", a[0] > a[n - 1] ? a[0] : a[n - 1]);
	delete[] a;
}