#include <algorithm>
#include <vector>
#include <iostream>
int kth(std::vector<int> &a, int k) {
	nth_element(a.begin(), a.begin() + k - 1, a.end());
	return a[k - 1];
}
int main() {
	std::vector<int> a(100);
	for(int i = 0; i < 100; i++) {
		a[i] = (i * 73) % 100;
	} std::cout << kth(a, 30);
}