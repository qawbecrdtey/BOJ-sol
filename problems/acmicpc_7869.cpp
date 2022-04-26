#include <iostream>
#include <cmath>
using namespace std;
using ld = long double;
inline ld dist(ld const a[3], ld const b[3]) {
    return sqrtl((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}
inline ld second(ld r1, ld r2, ld d) {
    return (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
}
int main() {
    cout.precision(3);
    cout << fixed;
    ld a[3], b[3];
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    ld const d = dist(a, b);
    if(d > a[2] + b[2]) {
        cout << "0.000";
        return 0;
    }
    if(d <= abs(a[2] - b[2])) {
        ld const r = min(a[2], b[2]);
        cout << r * r * M_PIl;
        return 0;
    }
    ld const t1 = acosl(second(a[2], b[2], d));
    ld const t2 = acosl(second(b[2], a[2], d));
    ld const S = sqrtl((d + a[2] + b[2]) * (a[2] + b[2] - d) * (b[2] + d - a[2]) * (d + a[2] - b[2]));
    cout << t1 * a[2] * a[2] + t2 * b[2] * b[2] - S / 2;
}