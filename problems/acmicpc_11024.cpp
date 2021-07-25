#include <iostream>
#include <string>
int main() {
	int t;
	std::cin >> t;
	std::string s;
	std::getline(std::cin, s);
	while(t--) {
		std::getline(std::cin, s);
		int idx = 0;
		int res = 0;
		while(idx < s.size()) {
			auto const start = idx;
			while(idx < s.size() && s[idx] != ' ') idx++;
			res += std::stoi(s.substr(start, idx - start));
			idx++;
		}
		std::cout << res << '\n';
	}
}