#include <stdio.h>
int f(int** arr, int const *a, int l, int r) {
	if(arr[l][r] != -1) return arr[l][r];
	if(l == r) return arr[l][r] = 0;
	if(r - l == 1) return arr[l][r] = (a[r] != a[l] ? 1 : 0);
	if(a[l] == a[r]) return arr[l][r] = f(arr, a, l + 1, r - 1);
	auto const x = f(arr, a, l + 1, r);
	auto const y = f(arr, a, l, r - 1);
	return arr[l][r] = (x > y ? y : x) + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto arr = new int*[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		arr[i] = new int[n];
		for(int j = 0; j < n; j++) {
			arr[i][j] = -1;
		}
	}
	printf("%d", f(arr, a, 0, n - 1));
	for(int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] a;
}