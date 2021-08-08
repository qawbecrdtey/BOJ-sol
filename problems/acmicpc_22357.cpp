#include <stdio.h>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}
int main() {
	int a[] = {1, 2000, 2001, 2003, 2009, 2011, 2017, 2021, 2027, 2029, 2033, 2039, 2041, 2053, 2057, 2063, 2069, 2077, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143};
	int x, y;
	scanf("%d%d", &x, &y);
	for(int i = 0; i < x; i++) {
		int sum = 1;
		for(int j = 0; j < y; j++) {
			printf("%d ", sum);
			sum += a[i];
		}
		printf("\n");
	}
}