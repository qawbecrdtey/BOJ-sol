#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x, y; cin >> x >> y;
    ll const z = 100 * y / x;
    if(z >= 99) { cout << -1; return 0; }
    ll const n = x * (z + 1) - 100 * y;
    ll const d = 99 - z;
    cout << (n + d - 1) / d;
}
