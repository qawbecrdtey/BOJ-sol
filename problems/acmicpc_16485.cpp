#include <iostream>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	std::cout << std::fixed;
	std::cout.precision(9);
	std::cout << (long double) a / b;
}