#include <cstdio>
using ll = long long;
constexpr ll M = 1000000000000;
int main() {
    int n; scanf("%d", &n);
    ll res = 1;
    for(int i = 2; i <= n; i++) {
        int val = i;
        while(val % 5 == 0) {
            val /= 5; res /= 2;
        }
        res *= val;
        res %= M;
    }
    printf("%05lld", res % 100000);
}