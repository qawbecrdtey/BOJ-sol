#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t; std::cin >> t; while(t--) {
        int a, b, c; std::cin >> a >> b >> c;
        std::cout << a << ' ' << b << ' ' << c << ' ';
        if(a + b + c != 180 || a <= 0 || b <= 0 || c <= 0) std::cout << "Check\n";
        else std::cout << "Seems OK\n";
    }
}