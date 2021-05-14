#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if(std::next_permutation(a, a + n)) {
		for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
	else printf("-1");
	delete[] a;
}