#include <iostream>
using namespace std;
using ll = long long;
constexpr ll fact[20] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000 };
inline ll get_sum(int n) {
    ll sum = 0, idx = 0;
    while(n) {
        if(n & 1) sum += fact[idx];
        idx++; n >>= 1;
    }
    return sum;
}
int main() {
    ll n; cin >> n;
    for(int i = 1; i < (1 << 20); i++) {
        ll const sum = get_sum(i);
        if(sum == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}