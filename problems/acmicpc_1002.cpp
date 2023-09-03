#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1 == x2 && y1 == y2) {
            cout << (r1 == r2 ? -1 : 0) << '\n';
            continue;
        }
        ll d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        ll r = r1 + r2;
        if(d > r * r) {
            cout << 0 << '\n';
            continue;
        }
        if(d == r * r) {
            cout << 1 << '\n';
            continue;
        }
        r = abs(r1 - r2);
        if(d > r * r) {
            cout << 2 << '\n';
            continue;
        }
        if(d == r * r) {
            cout << 1 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
}