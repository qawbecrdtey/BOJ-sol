#include <iostream>
int main() {
	long long a[7]; for(auto &i : a) std::cin >> i;
	std::cout << (a[0] * a[1] + a[2] * a[3]) * a[4] * a[5] * a[6];
}