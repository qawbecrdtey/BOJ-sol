#include <stdio.h>
#include <algorithm>
void f(int const *a, bool *b, int *arr, int n, int m, int cur) {
	if(cur == m) {
		for(int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < n; i++) {
		if(b[i]) continue;
		b[i] = true;
		arr[cur] = a[i];
		f(a, b, arr, n, m, cur + 1);
		b[i] = false;
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	auto b = new bool[n]();
	auto arr = new int[m]();
	f(a, b, arr, n, m, 0);
	delete[] arr;
	delete[] a;
	delete[] b;
}