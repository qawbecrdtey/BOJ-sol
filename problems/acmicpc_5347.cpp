#include <iostream>
#include <numeric>
using ll = long long;
int main() {
	int n;
	std::cin >> n;
	while(n--) {
		ll a, b;
		std::cin >> a >> b;
		std::cout << std::lcm(a, b) << '\n';
	}
}