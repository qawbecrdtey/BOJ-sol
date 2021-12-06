#include <iostream>
int main() {
    char s[99], t[99];
    std::cin >> s >> t;
    unsigned long x = std::stoll(s, nullptr, 2);
    unsigned long y = std::stoll(t, nullptr, 2);
    auto z = x * y;
    bool flag = false;
    for(int i = 63; i >= 0; i--) {
        if(flag || ((z >> i) & 1)) flag = true, std::cout << ((z >> i) & 1);
    }
}