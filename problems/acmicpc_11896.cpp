#include <cstdio>
int main() {
	long long a, b; scanf("%lld%lld", &a, &b);
	long long res = ((b / 2) * (b / 2 + 1)) - (((a - 1) / 2) * ((a - 1) / 2 + 1));
	if(a <= 2 && 2 <= b) res -= 2;
	printf("%lld", res);
}