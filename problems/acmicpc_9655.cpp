#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new bool[n + 1]();
	a[0] = true;
	for(int i = 1; i <= n; i++) {
		if(i < 3) {
			if(!a[i - 1]) a[i] = true;
		}
		else if(!(a[i - 1] && a[i - 3])) a[i] = true;
	}
	printf(a[n] ? "CY" : "SK");
	delete[] a;
}