#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		auto a = new int[n];
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		auto b = new int[n];
		int i = n;
	LP:	copy(a, a + n, b);
		for(int j = 0; j < n; j++) b[j] %= i;
		sort(b, b + n);
		for(int j = 1; j < n; j++) {
			if(b[j] == b[j - 1]) { i++; goto LP; }
		}
		printf("%d\n", i);
		delete[] a;
		delete[] b;
	}
}