#include <cstdio>
int main() {
	long long a[4]; for(auto &i : a) scanf("%lld", &i);
	long long x = a[0] * a[2], y = a[1] * a[3] * 2;
	printf("%d", !(x % y));
}