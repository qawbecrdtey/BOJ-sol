#include <cstdio>
#include <numeric>
int main() {
	long long a, b; scanf("%lld%lld", &a, &b);
	auto const g = std::gcd(a, b);
	printf("%lld", g * (a / g + b / g - 1));
}