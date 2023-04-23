#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll k, a, x, b, y; cin >> k >> a >> x >> b >> y;
    if(k <= a && k <= b) { cout << 0; return 0; }
    if(k <= a) { cout << (k - b) * y; return 0; }
    if(k <= b) { cout << (k - a) * x; return 0; }
    cout << max((k - b) * y + max(k - b - a, 0LL) * x, (k - a) * x + max(k - a - b, 0LL) * y);
}