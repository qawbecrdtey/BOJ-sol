#include <iostream>
#include <string>
#include <algorithm>

int main() {
    long long n;
    std::cin >> n;
    std::string s;
    while(n) {
        s.push_back(n % 2 + '0');
        n >>= 1;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}