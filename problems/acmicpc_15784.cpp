#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, a, b;
    std::cin >> n >> a >> b;
    int max = 0;
    int piv = 0;
    int x;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> x;
            if(i == a && j == b) piv = x;
            if((i == a || j == b) && max < x) max = x;
        }
    }
    if(piv != max) std::cout << "ANGRY";
    else std::cout << "HAPPY";
}