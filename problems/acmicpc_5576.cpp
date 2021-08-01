#include <stdio.h>
#include <algorithm>
int main() {
	int a[10], b[10];
	for(int &i : a) scanf("%d", &i);
	for(int &i : b) scanf("%d", &i);
	std::sort(a, a + 10);
	std::sort(b, b + 10);
	int aa = a[9] + a[8] + a[7];
	int bb = b[9] + b[8] + b[7];
	printf("%d %d", aa, bb);
}