#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c, d, t; cin >> a >> b >> c >> d >> t;
    if(abs(a - c) + abs(b - d) <= t && (t - abs(a - c) - abs(b - d)) % 2 == 0) cout << 'Y';
    else cout << 'N';
}