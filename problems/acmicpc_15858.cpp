#include <cstdio>
int main() {
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld.%.07lld", a * b / c, (long long)((long double)(a * b % c) / c * 10000000));

}