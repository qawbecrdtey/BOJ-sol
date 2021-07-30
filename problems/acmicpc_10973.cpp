#include <algorithm>
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if(!std::prev_permutation(a, a + n)) {
		printf("-1");
	}
	else {
		for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
}