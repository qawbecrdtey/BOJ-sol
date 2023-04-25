#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    double const invsq2 = 1 / sqrt(2);
    double x, y; cin >> x >> y; while(--n) {
        string s; double d; cin >> s >> d;
        if(s == "N") y += d;
        else if(s == "S") y -= d;
        else if(s == "E") x += d;
        else if(s == "W") x -= d;
        else if(s == "NE") y += invsq2 * d, x += invsq2 * d;
        else if(s == "NW") y += invsq2 * d, x -= invsq2 * d;
        else if(s == "SE") y -= invsq2 * d, x += invsq2 * d;
        else if(s == "SW") y -= invsq2 * d, x -= invsq2 * d;
        else __builtin_unreachable();
    } cout.precision(12); cout << fixed << x << ' ' << y;
}