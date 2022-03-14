#include <algorithm>
#include <stdio.h>
#include <vector>
inline std::vector<int> get_primes() {
    std::vector<int> primes = { 2, 3 };
    std::vector<bool> visited(4000000);
    int i = 5, d = 4;
    for(; i <= 2000; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int k = i; k < 4000000; k += (i << 1)) {
                visited[k] = true;
            }
        }
    }
    for(; i <= 4000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
inline bool contains(int n, int d) {
    while(n) {
        if(n % 10 == d) return true;
        n /= 10;
    } return false;
}
int main() {
    int a, b, d;
    auto primes = get_primes();
    scanf("%d%d%d", &a, &b, &d);
    auto const l = std::lower_bound(primes.begin(), primes.end(), a);
    auto const r = std::upper_bound(primes.begin(), primes.end(), b);
    int cnt = 0;
    for(auto it = l; it != r; ++it) {
        cnt += contains(*it, d);
    } printf("%d", cnt);
}