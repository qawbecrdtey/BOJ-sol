#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(!v.empty() && v.back() >= x) {
			*std::lower_bound(v.begin(), v.end(), x) = x;
		}
		else v.push_back(x);
	}
	std::cout << v.size();
}