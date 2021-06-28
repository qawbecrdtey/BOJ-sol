#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int t = i;
        int sum = 0;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        cnt += (i % sum == 0);
    }
    printf("%d", cnt);
}