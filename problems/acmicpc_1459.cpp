#include <stdio.h>
int main() {
	long long x, y, w, s;
	scanf("%lld%lld%lld%lld", &x, &y, &w, &s);
	long long res = (x + y) * w;
	if(res > ((x > y) ? y : x) * s + ((x > y) ? (x - y) : (y - x)) * w) res = ((x > y) ? y : x) * s + ((x > y) ? (x - y) : (y - x)) * w;
	if(res > (x > y ? y : x) * s + ((x + y) % 2) * w + (x > y ? x - y - ((x + y) % 2) : y - x - ((x + y) % 2)) * s) {
		res = (x > y ? y : x) * s + ((x + y) % 2) * w + (x > y ? x - y - ((x + y) % 2) : y - x - ((x + y) % 2)) * s;
	}
	printf("%lld", res);
}