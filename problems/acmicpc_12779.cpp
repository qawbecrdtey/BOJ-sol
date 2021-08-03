#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;
ll sqrt(ll x) {
    ll l = 0, r = x + 1;
    ll res = 0;
    while(l < r) {
        auto const m = (l + r) / 2;
        if(m > (1 << 30)) {
            r = m; continue;
        }
        if(m * m == x) return m;
        if(m * m < x) {
            res = m;
            l = m + 1;
            continue;
        }
        r = m;
    }
    return res;
}
int main() {
    ll a, b;
    cin >> a >> b;
    ll num = sqrt(b) - sqrt(a), den = b - a;
    if(!num) {
        cout << 0;
        return 0;
    }
    ll g = gcd(num, den);
    cout << num / g << '/' << den / g;
}