#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll x = 1, res = 0;
    while(b) {
        if(a & x) {
            x <<= 1;
            continue;
        }
        if(b & 1) a |= x, res |= x;
        b >>= 1; x <<= 1;
    } cout << res;
}