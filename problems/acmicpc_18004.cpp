#include <iostream>
int main() {
    int a, b, c = 0;
    std::cin >> a >> b;
    while (a > b) {
        c += 1 + (a & 1);
        a = (a + 1) / 2;
    }
    std::cout << c + b - a;
}