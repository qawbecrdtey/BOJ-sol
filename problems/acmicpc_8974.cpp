#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int arr[1000], cur = 1, left = 1;
	for(int i = 1; i <= b; i++) {
		arr[i] = cur; left--;
		if(!left) left = ++cur;
	} int sum = 0;
	for(int i = a; i <= b; i++) {
		sum += arr[i];
	} printf("%d", sum);
}