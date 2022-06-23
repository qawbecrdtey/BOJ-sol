#include <iostream>
int main() {
    long long n; std::cin >> n;
    if(!n) {
        std::cout << "NO";
        return 0;
    }
    while(n) {
        if(n % 3 == 2) {
            std::cout << "NO";
            return 0;
        } n /= 3;
    } std::cout << "YES";
}