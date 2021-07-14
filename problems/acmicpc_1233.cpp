#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	auto arr = new int[a + b + c + 1]();
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			for(int k = 1; k <= c; k++) {
				arr[i + j + k]++;
			}
		}
	}
	int maxi = 1;
	for(int i = 2; i <= a + b + c; i++) {
		if(arr[maxi] < arr[i]) maxi = i;
	}
	printf("%d", maxi);
	delete[] arr;
}