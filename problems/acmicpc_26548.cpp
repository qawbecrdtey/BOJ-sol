#include <cmath>
#include <iostream>
using namespace std;
using ld = long double;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(3);
    int t; cin >> t; while(t--) {
        ld a, b, c; cin >> a >> b >> c;
        ld x = sqrtl(b * b - 4 * a * c);
        cout << fixed << (x - b) / (2 * a) << ", " << -(x + b) / (2 * a) << '\n';
    }
}