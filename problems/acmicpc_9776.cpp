#include <cmath>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; double res = 0; while(t--) {
        char c[2]; cin >> c;
        switch(*c) {
            case 'C': {
                double r, h; cin >> r >> h;
                res = max(res, (M_PI * r * r * h) / 3);
            } break;
            case 'L': {
                double r, h; cin >> r >> h;
                res = max(res, M_PI * r * r * h);
            } break;
            case 'S': {
                double r; cin >> r;
                res = max(res, (M_PI * r * r * r) * 4 / 3);
            } break;
            default: __builtin_unreachable();
        }
    } cout.precision(3); cout << fixed << res;
}