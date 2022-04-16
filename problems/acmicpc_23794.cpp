#include <iostream>
int main() {
	int n; std::cin >> n;
	for(int i = 0; i < n + 2; i++) std::cout << '@'; std::cout << '\n';
	for(int i = 1; i < n + 1; i++) {
		std::cout << '@';
		for(int j = 1; j < n + 1; j++) std::cout << ' ';
		std::cout << "@\n";
	} for(int i = 0; i < n + 2; i++) std::cout << '@';
}