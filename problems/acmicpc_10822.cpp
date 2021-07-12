#include <iostream>
#include <string>
int main() {
	std::string s;
	std::cin >> s;
	int piv = 0;
	int sum = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ',') { sum += std::stoi(s.substr(piv, i - piv)); piv = i + 1; }
	}
	printf("%d", sum + std::stoi(s.substr(piv)));
}