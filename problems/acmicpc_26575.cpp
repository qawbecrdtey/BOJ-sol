#include <iostream>
using namespace std;
using ld = long double;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(2);
    int t; cin >> t; while(t--) {
        ld a, b, c; cin >> a >> b >> c; cout << fixed << '$' << a * b * c << '\n';
    }
}