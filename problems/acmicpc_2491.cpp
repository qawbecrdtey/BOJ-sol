#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	auto b = new int[n]();
	int max = 0;
	b[0] = 1;
	for(int i = 1; i < n; i++) {
		if(a[i - 1] <= a[i]) b[i] = b[i - 1] + 1;
		else b[i] = 1;
		if(max < b[i]) max = b[i];
	}
	delete[] b;
	b = new int[n]();
	b[0] = 1;
	for(int i = 0; i < n; i++) {
		if(a[i - 1] >= a[i]) b[i] = b[i - 1] + 1;
		else b[i] = 1;
		if(max < b[i]) max = b[i];
	}
	printf("%d", max);
	delete[] b;
	delete[] a;
}