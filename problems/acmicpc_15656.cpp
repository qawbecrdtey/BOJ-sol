#include <stdio.h>
#include <algorithm>
void f(int const *a, int *arr, int const n, int const m, int cnt) {
	if(cnt == m) {
		for(int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < n; i++) {
		arr[cnt] = a[i];
		f(a, arr, n, m, cnt + 1);
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
	auto arr = new int[n];
	f(a, arr, n, m, 0);
	delete[] a;
}