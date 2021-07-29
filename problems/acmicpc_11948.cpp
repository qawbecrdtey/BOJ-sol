#include <algorithm>
#include <stdio.h>
int main() {
	int a[4], b[2];
	for(auto &i : a) scanf("%d", &i);
	for(auto &i : b) scanf("%d", &i);
	std::sort(a, a + 4);
	std::sort(b, b + 2);
	printf("%d", a[3] + a[2] + a[1] + b[1]);
}