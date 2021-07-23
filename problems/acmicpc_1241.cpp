#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	int max = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(max < a[i]) max = a[i];
	}
	auto arr = new int[max + 1]();
	for(int i = 0; i < n; i++) {
		arr[a[i]]++;
	}
	for(int i = 0; i < n; i++) {
		int res = 0;
		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				res += arr[j];
				if(j * j != a[i]) {
					res += arr[a[i] / j];
				}
			}
		}
		printf("%d\n", res - 1);
	}
	delete[] arr;
	delete[] a;
}