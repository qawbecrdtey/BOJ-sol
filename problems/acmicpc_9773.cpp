#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        ll m = n, sum{}; while(m) {
            sum += m % 10;
            m /= 10;
        }
        auto res = (n % 1000) * 10 + sum;
        if(res > 9999) res %= 10000;
        else if(res < 1000) res += 1000;
        printf("%04lld\n", res);
    }
}